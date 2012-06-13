create table CLIENT (
	num number,
	nom varchar2(20),
	prenom varchar2(20),
	adresse varchar2(128),
	date_nais date,
	tel varchar2(20),
	sexe char check (sexe in ('m','f')),
	constraint PK_CLIENT primary key (num)
);

create sequence client_seq
INCREMENT BY 1
START WITH 1
NOMAXVALUE
NOCYCLE
CACHE 10;

create table FACTURE (
	num number,
	date_etabli date,
	client number,
	constraint PK_FACTURE primary key (num),
	constraint FK_FACTURE_CLIENT foreign key (client) references CLIENT(num)
);

create sequence facture_seq
INCREMENT BY 1
START WITH 1
NOMAXVALUE
NOCYCLE
CACHE 10;

create table PRODUIT (
	num number,
	designation varchar2(128),
	prix number,
	stock number,
	constraint PK_PRODUIT primary key (num)
);

create sequence produit_seq
INCREMENT BY 1
START WITH 1
NOMAXVALUE
NOCYCLE
CACHE 10;

create table LIGNE_FACT (
	facture number,
	produit number,
	qte number,
	constraint FK_LIGNE_FACT_FACTURE foreign key (facture) references FACTURE(num),
	constraint FK_LIGNE_FACT_PRODUIT foreign key (produit) references PRODUIT(num),
	constraint PK_LIGNE_FACT primary key (facture, produit)
);