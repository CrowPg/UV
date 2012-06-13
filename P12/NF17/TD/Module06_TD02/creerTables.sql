CREATE TABLE tSession(
	id int,
	debut timestamp UNIQUE NOT NULL,
	fin timestamp UNIQUE NOT NULL,
	PRIMARY KEY(id));
	
CREATE TABLE tGroupe(
	pkLogin char(7),
	aPassword char(8),
	session int,
	PRIMARY KEY (pkLogin),
	FOREIGN KEY (session) REFERENCES tSession(id));
	