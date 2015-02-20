--  AUTOMATICALLY GENERATED - DO NOT EDIT!

--  All session_info-based criteria

--  Collect
DROP VIEW IF EXISTS max_cipher;
CREATE VIEW max_cipher AS
SELECT mcc, mnc, lac, cid, lu_acc, max(cipher) as max
FROM session_info
WHERE domain = 0 AND mcc > 0 AND mnc > 0 AND lac > 0 AND cid > 0 AND (lu_acc OR call_presence OR sms_presence)
GROUP BY mcc, mnc, lac, cid, lu_acc;

DROP VIEW IF EXISTS c1;
CREATE VIEW c1 AS
SELECT
        si.id,
        si.timestamp,
        si.mcc,
        si.mnc,
        si.lac,
        si.cid,
        cipher as value,
        mc.max as threshold,
        cipher < mc.max AS score
FROM session_info AS si, max_cipher as mc
ON si.mcc = mc.mcc AND si.mnc = mc.mnc AND si.lac = mc.lac AND si.cid = mc.cid AND si.lu_acc = mc.lu_acc
WHERE domain = 0;
DROP VIEW IF EXISTS c2;
CREATE VIEW c2 AS
SELECT
        si.id,
        si.timestamp,
        si.mcc,
        si.mnc,
        si.lac,
        si.cipher_delta as value,
        si.cipher_delta > config.delta_cmcp as score
FROM session_info AS si, config
WHERE domain = 0 AND cipher = 1;
DROP VIEW IF EXISTS c3;
CREATE VIEW c3 AS
SELECT
        id,
        timestamp,
        mcc,
        mnc,
        lac,
        (CASE WHEN cmc_imeisv > 0 THEN 0 ELSE 0.57 END) as score
FROM session_info
WHERE domain = 0 AND cipher > 0;
DROP VIEW IF EXISTS c4;
CREATE VIEW c4 AS
SELECT
        id,
        timestamp,
        mcc,
        mnc,
        lac,
        cid,
        (CASE
			WHEN auth = 0 THEN 2.0
			WHEN auth = 1 THEN 0.5
			ELSE 0.0
		END) *
		(CASE
			WHEN (iden_imei_bc = 0 AND iden_imei_ac = 0) THEN 1.0
			ELSE 3.0
		END)
			as score
FROM session_info
WHERE
	domain = 0  AND
	cipher = 0  AND
	t_locupd    AND
	lu_type = 0 AND
	lu_reject   AND
	iden_imsi_bc;
DROP VIEW IF EXISTS c5;
CREATE VIEW c5 AS
SELECT
        si.id,
        si.timestamp,
        si.mcc,
        si.mnc,
        si.lac,
        si.cid,
        CASE WHEN cipher = 0 THEN 1 ELSE 0 END score
FROM session_info AS si
WHERE
	domain = 0 AND
	((t_locupd AND lu_acc) OR t_call OR t_sms);

--  Track
DROP VIEW IF EXISTS t3;
CREATE VIEW t3 AS
SELECT
        id,
        mcc,
        mnc,
        lac,
        cid,
        CASE WHEN
        (paging_mi        AND
         mobile_term      AND
         t_release        AND
         NOT auth         AND
         NOT iden_imei_ac AND
         NOT iden_imei_bc AND
         NOT iden_imsi_ac AND
         NOT iden_imsi_bc AND
         NOT cipher > 0   AND
         NOT sms_presence AND
         NOT call_presence) THEN 1 ELSE 0 END as score
FROM session_info
WHERE domain = 0;
DROP VIEW IF EXISTS t4;
CREATE VIEW t4 AS
SELECT
        id,
        mcc,
        mnc,
        lac,
        cid,
        duration,
        CASE WHEN
         ((assign_cmpl OR mobile_term) AND
          t_release                    AND
          NOT auth                     AND
          NOT iden_imei_ac             AND
          NOT iden_imei_bc             AND
          NOT iden_imsi_ac             AND
          NOT iden_imsi_bc             AND
          NOT cipher > 0               AND
          NOT sms_presence             AND
          NOT call_presence            AND
          duration > config.delta_tch) THEN 1 ELSE 0 END as score
FROM session_info, config
WHERE domain = 0 AND duration > 0;

--  Result
DROP VIEW IF EXISTS si;
CREATE VIEW si AS
SELECT
        si.id,
        si.timestamp,
        si.duration/1000 as duration,
        si.mcc,
        si.mnc,
        si.lac,
        si.cid,
        ifnull(c1.score, 0) as c1,
        ifnull(c2.score, 0) as c2,
        ifnull(c3.score, 0) as c3,
        ifnull(c4.score, 0) as c4,
        ifnull(c5.score, 0) as c5,
        ifnull(t3.score, 0) as t3,
        ifnull(t4.score, 0) as t4
FROM session_info as si LEFT JOIN
    c1 ON si.id = c1.id LEFT JOIN
    c2 ON si.id = c2.id LEFT JOIN
    c3 ON si.id = c3.id LEFT JOIN
    c4 ON si.id = c4.id LEFT JOIN
    c5 ON si.id = c5.id LEFT JOIN
    t3 ON si.id = t3.id LEFT JOIN
    t4 ON si.id = t4.id
WHERE si.domain = 0 AND si.mcc > 0 AND si.mnc > 0 AND si.lac > 0 AND si.cid > 0;
--  All cell_info-based criteria

--  Attract
--  A1

--  Select all cell_info entries which have been observed within
--  'delta_arfcn' seconds broadcasting a different MCC/MNC/LAC/CID
DROP VIEW IF EXISTS dup_arfcns;
CREATE VIEW dup_arfcns AS
SELECT
        l.bcch_arfcn AS bcch_arfcn,
        min(l.first_seen) AS first_seen,
        max(l.last_seen) AS last_seen,
        count(*) AS value
FROM cell_info AS l, cell_info AS r, config
ON
        l.bcch_arfcn = r.bcch_arfcn AND
        (l.mcc != r.mcc OR
         l.mnc != r.mnc OR
         l.lac != r.lac OR
         l.cid != r.cid) AND
        (strftime('%s', l.first_seen) - strftime('%s', r.last_seen)) >= 0 AND
        (strftime('%s', l.first_seen) - strftime('%s', r.last_seen)) < config.delta_arfcn
WHERE
        l.mcc > 0 AND l.mnc > 0 AND l.lac > 0 AND l.cid > 0 AND
        r.mcc > 0 AND r.mnc > 0 AND r.lac > 0 AND r.cid > 0
GROUP BY l.bcch_arfcn;

--  Associate a1 score
DROP VIEW IF EXISTS a1;
CREATE VIEW a1 AS
SELECT
        ci.id,
        ci.mcc,
        ci.mnc,
        ci.lac,
        ci.cid,
        ifnull(da.value, 0) as value,
        CASE WHEN da.value > 1 THEN 1 ELSE 0 END as score
FROM cell_info AS ci LEFT JOIN dup_arfcns AS da
ON
        ci.bcch_arfcn = da.bcch_arfcn AND
        strftime('%s', ci.first_seen) >= strftime('%s', da.first_seen) AND
        strftime('%s', ci.last_seen)  <= strftime('%s', da.last_seen)
WHERE
        ci.mcc > 0 AND ci.mnc > 0 and ci.lac > 0 and ci.cid > 0;
--  A2

DROP VIEW IF EXISTS a2;
CREATE VIEW a2 AS
SELECT DISTINCT
        cell.id,
        cell.mcc,
        cell.mnc,
        cell.lac,
        cell.cid,
        sum(CASE WHEN cell.lac != neig.lac THEN 1.0 ELSE 0.0 END)/count(*) as score
FROM cell_info AS cell, arfcn_list AS al, cell_info AS neig, config
ON cell.id = al.id AND al.arfcn = neig.bcch_arfcn
WHERE
        cell.mcc > 0 AND cell.mnc > 0 AND cell.lac > 0 AND cell.cid > 0
GROUP BY cell.id;
--  A4

--  Join cell info with itself on all entries that have the same
--  MCC/MNC/LAC/CID, but were observed on different ARFCNs. This
--  my happen when cells are reconfigured, but this should be rare.
--  FIXME: When more test data is available we could decide to make
--  the score dependent on the timestamp delta between the occurrences
--  of the conflicting cell infos.
DROP VIEW IF EXISTS a4;
CREATE VIEW a4 as
SELECT
        l.id,
        l.mcc,
        l.mnc,
        l.lac,
        l.cid,
        count(*) AS value,
        CASE WHEN count(*) > 1 THEN 1 ELSE 0 END AS score
FROM cell_info AS l LEFT JOIN cell_info AS r
ON
        l.mcc = r.mcc AND
        l.mnc = r.mnc AND
        l.lac = r.lac AND
        l.cid = r.cid AND
        l.bcch_arfcn != r.bcch_arfcn AND
        l.first_seen < r.first_seen
WHERE
        l.mcc > 0 AND
        l.mnc > 0 AND
        l.lac > 0 AND
        l.cid > 0 AND
        r.bcch_arfcn != null
GROUP BY l.mcc, l.mnc, l.lac, l.cid;

--  Keep
--  FIXME: Disable this test until we have the ARFCN/cell collection issue
--  sorted out, as it leads to false positives.

--  K1
DROP VIEW IF EXISTS k1;
CREATE VIEW k1 AS
SELECT
	0 as id,
	0 as mcc,
	0 as mnc,
	0 as lac,
	0 as cid,
	0.0 as score;

--  CREATE VIEW k1 AS
--  SELECT
--          cell.id,
--          cell.mcc,
--          cell.mnc,
--          cell.lac,
--          cell.cid,
--          sum(CASE WHEN ifnull(al.arfcn, 0) > 0 THEN 0 ELSE 1 END) = 0 as score
--  FROM cell_info AS cell LEFT JOIN arfcn_list AS al
--  ON cell.id = al.id
--  GROUP BY cell.id
--  K2
drop view if exists k2;
create view k2 as
select
        id,
        mcc,
        mnc,
        lac,
        cid,
        cro as value,
        (cro > config.cro_max) as score
from cell_info, config
where mcc > 0 and mnc > 0 and lac > 0 and cid > 0 and cro > 0;

--  Track
DROP VIEW IF EXISTS t1;
CREATE VIEW t1 AS
SELECT
        id,
        mcc,
        mnc,
        lac,
        cid,
        t3212 AS value,
        t3212 < config.t3212_min AS score
FROM cell_info, config
WHERE t3212 > 0;

--  Reject
-- R1

--  For every cell info for which a MCC/MNC/LAC/CID was recorded,
--  add a column with the neighboring ARFCN for each entry created
--  from BCCH/SI2 with the same ID in the arfcn_list table.
DROP VIEW IF EXISTS cells_with_neig_arfcn;
CREATE VIEW cells_with_neig_arfcn AS
SELECT
        ci.id,
        ci.mcc,
        ci.mnc,
        ci.lac,
        ci.cid,
        ci.bcch_arfcn,
        al.arfcn as neig_arfcn
FROM cell_info AS ci LEFT JOIN arfcn_list AS al
ON ci.id = al.id
WHERE ci.mcc > 0 AND ci.mnc > 0 AND ci.lac > 0 AND ci.cid > 0 AND al.source = "SI2";

--  Join the cells_with_neig_arfcn table above with itself, such
--  that that for every cell in cell_info we get the respective 
--  neighboring cell information, if present. This is the case
--  when the neighbor ARFCN (neig_arfcn) equals the main ARFCN
--  (bcch_arfcn) of the joined table.
DROP VIEW IF EXISTS cells_with_neig_cell;
CREATE VIEW cells_with_neig_cell AS
SELECT DISTINCT
        c.id,
        c.mcc as cell_mcc,
        c.mnc as cell_mnc,
        c.lac as cell_lac,
        c.cid as cell_cid,
        c.bcch_arfcn as cell_arfcn,
        n.id as neig_id
FROM cells_with_neig_arfcn as c, cells_with_neig_arfcn as n
ON c.neig_arfcn = n.bcch_arfcn;

--  Count the number of neighboring cells recorded for every cell
--  in the table. Note, that this is the number of neighboring
--  cells we actually received SI2 information for (as an inner
--  join is used above). This count will later be used as the
--  number of neighboring cells that should have the cell in their
--  own ARFCN list.
--  This makes sense, as you may not receive BCCH info from ap
--  neighboring cell on the far other end of you current cell.
--  This is normal and should not lead to a high score. This is
--  only the case if a (supposed) neighboring cell that we
--  receive SI2 info from does not announce the current cell as
--  their own neighbor.
DROP VIEW IF EXISTS cells_neig_count;
CREATE VIEW cells_neig_count AS
SELECT *, count(*) as count
FROM cells_with_neig_cell 
GROUP BY id, cell_mcc, cell_mnc, cell_lac, cell_cid;

--  This is the list neighboring cells that reference a cell.
--  It is similar to cells_with_neig_cell, just that we also
--  join on the neigboring cells ARFCN from SI2 equalling 
--  the current cells main ARFCN.
DROP VIEW IF EXISTS cells_ref_by_neig_cell;
CREATE VIEW cells_ref_by_neig_cell AS
SELECT DISTINCT
        c.id,
        c.mcc as cell_mcc,
        c.mnc as cell_mnc,
        c.lac as cell_lac,
        c.cid as cell_cid,
        c.bcch_arfcn as cell_arfcn,
        n.id as neig_id
FROM cells_with_neig_arfcn as c, cells_with_neig_arfcn as n
ON c.neig_arfcn = n.bcch_arfcn AND c.bcch_arfcn = n.neig_arfcn;

--  Count by how many neigboring cells a cell is announce
--  as neighboring cell.
DROP VIEW IF EXISTS cells_ref_by_neig_count;
CREATE VIEW cells_ref_by_neig_count AS
SELECT id, count(*) as count 
FROM cells_ref_by_neig_cell
GROUP BY cell_mcc, cell_mnc, cell_lac, cell_cid, cell_arfcn
ORDER BY id;

--  Join both counts. For each cell, divide the number of
--  reachable neigboring cells by which the cell is announced
--  by the number of neighboring cells that should announce
--  it.
DROP VIEW IF EXISTS r1;
CREATE VIEW r1 AS
SELECT 
        cn.id,
        cn.cell_mcc AS mcc,
        cn.cell_mnc AS mnc,
        cn.cell_lac AS lac,
        cn.cell_cid AS cid,
        1 - (crbn.count + 0.0)/cn.count as score
FROM cells_neig_count as cn, cells_ref_by_neig_count as crbn
ON cn.id = crbn.id;
--  R2

--  From the CatcherCatcher model:
--
--  N = (9 − BS_AG_BLKS_RES − 6 · BS_CCCH_SDCCH_COMB) · BS_PA_MFRMS
--  BS_AG_BLKS_RES:     BCCH/SI3, Cell database field cell_info.agch_blocks
--  BS_CCCH_SDCCH_COMB: BCCH/SI3, Cell database field cell_info.combined
--  BS_PA_MFRMS:        BCCH/SI3, Cell database field cell_info.pag_mframes

DROP VIEW IF EXISTS r2;
CREATE VIEW r2 AS
SELECT
        id,
        mcc,
        mnc,
        cid,
        lac,
        ((9 - cell_info.agch_blocks - 6 * cell_info.combined) * cell_info.pag_mframes) > config.n_norm as score
FROM cell_info, config;

--  Fingerprint
DROP VIEW IF EXISTS f1;
-- CREATE VIEW f1 AS
-- SELECT
-- 	si.id,
-- 	min(si2.id),
-- 	si.mcc,
-- 	si.mnc,
-- 	si.lac,
-- 	si.cid,
-- 	count(pag1_rate) as count,
-- 	avg(pag1_rate) < config.min_pag1_rate as score
-- FROM
-- 	session_info AS si, session_info as si2, paging_info AS pi, config
-- ON
-- 	--  Join on the next location update…
-- 	si2.id > si.id AND
-- 	--  …all paging messages since the current location update started…
-- 	strftime('%s', pi.timestamp) - strftime('%s', si.timestamp - si.duration/1000) > 0 AND
-- 	--  …until the succeeding location update starts…
-- 	strftime('%s', si2.timestamp) - si2.duration/1000 - strftime('%s', pi.timestamp) > 0
-- WHERE
-- 	si.domain = 0 AND si2.domain = 0 AND si.lu_acc AND si2.lu_acc
-- GROUP BY
-- 	si.id

CREATE VIEW f1 AS
SELECT
	0 as id,
	0,
	0 as mcc,
	0 as mnc,
	0 as lac,
	0 as cid,
	0 as count,
	0 as score;

--  Result
DROP VIEW IF EXISTS ci;
CREATE VIEW ci AS
SELECT DISTINCT
        ci.first_seen as first_seen,
        ci.last_seen as last_seen,
        ci.mcc,
        ci.mnc,
        ci.lac,
        ci.cid,
        ifnull(a1.score, 0) as a1,
        ifnull(a2.score, 0) as a2,
        ifnull(a4.score, 0) as a4,
        ifnull(k1.score, 0) as k1,
        ifnull(k2.score, 0) as k2,
        ifnull(t1.score, 0) as t1,
        ifnull(r1.score, 0) as r1,
        ifnull(r2.score, 0) as r2,
        ifnull(f1.score, 0) as f1
FROM cell_info as ci LEFT JOIN
 a1 ON ci.id = a1.id LEFT JOIN
 a2 ON ci.id = a2.id LEFT JOIN
 a4 ON ci.id = a4.id LEFT JOIN
 k1 ON ci.id = k1.id LEFT JOIN
 k2 ON ci.id = k2.id LEFT JOIN
 t1 ON ci.id = t1.id LEFT JOIN
 r1 ON ci.id = r1.id LEFT JOIN
 r2 ON ci.id = r2.id LEFT JOIN
 f1 ON ci.id = f1.id
WHERE
	ci.mcc > 0 AND ci.mnc > 0 AND ci.lac > 0 AND ci.cid > 0;

--  All unavailable criteria

--  Attract
--  A3: N/A
--  RAT not available

--  Track
--  Tx level not availble

DELETE FROM catcher;
INSERT INTO catcher
SELECT
	si.id,
	si.mcc,
	si.mnc,
	si.lac,
	si.cid,
	si.timestamp,
	si.duration,
	ifnull(max(ci.a1), 0.0),
	ifnull(max(ci.a2), 0.0),
	ifnull(max(ci.a4), 0.0),
	ifnull(max(ci.k1), 0.0),
	ifnull(max(ci.k2), 0.0),
	ifnull(max(si.c1), 0.0),
	ifnull(max(si.c2), 0.0),
	ifnull(max(si.c3), 0.0),
	ifnull(max(si.c4), 0.0),
	ifnull(max(si.c5), 0.0),
	ifnull(max(ci.t1), 0.0),
	ifnull(max(si.t3), 0.0),
	ifnull(max(si.t4), 0.0),
	ifnull(max(ci.r1), 0.0),
	ifnull(max(ci.r2), 0.0),
	ifnull(max(ci.f1), 0.0),
	ifnull(si_loc.longitude, 0.0),
	ifnull(si_loc.latitude, 0.0),
	ifnull(si_loc.valid, 0),
	ifnull(max(ci.a1), 0.0) +
	ifnull(max(ci.a2), 0.0) +
	ifnull(max(ci.a4), 0.0) +
	ifnull(max(ci.k1), 0.0) +
	ifnull(max(ci.k2), 0.0) +
	ifnull(max(si.c1), 0.0) +
	ifnull(max(si.c2), 0.0) +
	ifnull(max(si.c3), 0.0) +
	ifnull(max(si.c4), 0.0) +
	ifnull(max(si.c5), 0.0) +
	ifnull(max(ci.t1), 0.0) +
	ifnull(max(si.t3), 0.0) +
	ifnull(max(si.t4), 0.0) +
	ifnull(max(ci.r1), 0.0) +
	ifnull(max(ci.r2), 0.0) +
	ifnull(max(ci.f1), 0.0) as score
FROM si LEFT JOIN ci
ON
	ci.mcc = si.mcc AND
	ci.mnc = si.mnc AND
	ci.lac = si.lac AND
	ci.cid = si.cid AND
	abs(strftime('%s', ci.last_seen) - strftime('%s', si.timestamp)) < 10000
LEFT JOIN si_loc
ON
	si.id = si_loc.id,
config
GROUP BY
	si.id
HAVING
	score > config.catcher_min_score
;
