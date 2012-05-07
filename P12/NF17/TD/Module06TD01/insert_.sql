INSERT INTO dept2 (dep_id, dep_nom ,nbhabitants)
SELECT SUBSTR(departement, 1, 2), SUBSTR(departement, 6), nbhabitants FROM dep
;