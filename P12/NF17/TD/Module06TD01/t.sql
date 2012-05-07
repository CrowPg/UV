CREATE TABLE t(
	a int,
	b varchar(50), 
	c int,
	PRIMARY KEY(a),
	FOREIGN KEY(c) REFERENCES t(a));