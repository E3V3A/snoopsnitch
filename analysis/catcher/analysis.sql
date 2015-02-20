.read analysis_si.sql
.read analysis_ci.sql

--  All unavailable criteria

--  Attract
.read sql/a_03.sql

--  Track
.read sql/t_07.sql

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
