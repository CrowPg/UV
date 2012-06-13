-- Facture 1

insert into FACTURE(num, client, date_etabli) values(
	facture_seq.NEXTVAL,
	2,
	to_date('20122000','DDMMYYYY')
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	1,
	1
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	2,
	2
);

-- Facture 2

insert into FACTURE(num, client, date_etabli) values(
	facture_seq.NEXTVAL,
	2,
	to_date('01012001','DDMMYYYY')
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	1,
	2
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	3,
	1
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	2,
	2
);

-- Facture 3

insert into FACTURE(num, client, date_etabli) values(
	facture_seq.NEXTVAL,
	2,
	to_date('17112004','DDMMYYYY')
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	1,
	2
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	2,
	4
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	3,
	1
);

-- Facture 4

insert into FACTURE(num, client, date_etabli) values(
	facture_seq.NEXTVAL,
	3,
	to_date('14012004','DDMMYYYY')
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	2,
	1
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	3,
	1
);

-- Facture 5

insert into FACTURE(num, client, date_etabli) values(
	facture_seq.NEXTVAL,
	4,
	to_date('19022004','DDMMYYYY')
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	1,
	2
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	3,
	3
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	2,
	4
);

-- Facture 6

insert into FACTURE(num, client, date_etabli) values(
	facture_seq.NEXTVAL,
	4,
	to_date('17032004','DDMMYYYY')
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	1,
	7
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	2,
	3
);

insert into LIGNE_FACT(facture, produit, qte) values(
	facture_seq.CURRVAL,
	3,
	1
);

commit;
