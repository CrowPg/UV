create table SPECIALITE (

  intitule varchar2(20),

  constraint PK_SPECIALITE primary key (intitule)

);

create table MEMBRE (

  prenom varchar2(20),

  nom varchar2(20),

  specialite varchar2(20),

  constraint PK_MEMBRE primary key (prenom),

  constraint FK_MEMBRE_SPECIALITE foreign key (specialite) references SPECIALITE(intitule)

);

create table PROJET (

  num number,

  nom varchar2(20),

  debut date,

  fin date,

  chefprojet varchar2(20),

  specialite varchar2(20),

  constraint PK_PROJET primary key (num),

  constraint FK_PROJET_MEMBRE foreign key (chefprojet) references MEMBRE(prenom),

  constraint FK_PROJET_SPECIALITE foreign key (specialite) references SPECIALITE(intitule)

);

create table TACHE (

  num number,

  projet number,

  nom varchar2(20),

  debut date,

  fin date,

  constraint FK_TACHE_PROJET foreign key (projet) references PROJET(num),

  constraint PK_TACHE primary key (num, projet)

);

create table PARTENAIRE (

  nom varchar2(40),

  description varchar2(128),

  constraint PK_PARTENAIRE primary key (nom)

);

create table PARTICIPE (

  prenom varchar2(20),

  tache number,

  projet number,

  fonction varchar2(60),

  constraint FK_PARTICIPE_MEMBRE foreign key (prenom) references MEMBRE(prenom),

  constraint FK_PARTICIPE_TACHE foreign key (tache, projet) references TACHE(num, projet),

  constraint PK_PARTICIPE primary key (prenom, tache, projet)

);

create table ESTASSOCIE (

  nom varchar2(40), projet number,

  role varchar2(128),

  constraint FK_ESTASSOCIE_PARTENAIRE foreign key (nom) references PARTENAIRE(nom),

  constraint FK_ESTASSOCIE_PROJET foreign key (projet) references PROJET(num),

  constraint PK_ASTASSOCIE primary key (nom, projet)

);

INSERT INTO Specialite VALUES ('Ville');

INSERT INTO Specialite VALUES ('Université');

INSERT INTO Specialite VALUES ('Sport');

INSERT INTO Specialite VALUES ('Entreprise');

INSERT INTO Specialite VALUES ('Culture');

INSERT INTO Specialite VALUES ('International');

INSERT INTO Membre VALUES ('Nathalie', 'Dupont', 'Culture');

INSERT INTO Membre VALUES ('Pierre', 'Perret', 'Sport');

INSERT INTO Membre VALUES ('Alain', 'Durand', 'Culture');

INSERT INTO Membre VALUES ('Julien', 'Dujnou', 'Université');

INSERT INTO Projet VALUES (1, 'Comédie Musicale', TO_DATE('20020901','YYYYMMDD'), TO_DATE('20021130', 'YYYYMMDD'), 'Nathalie', 'Culture');

INSERT INTO Projet VALUES (2, 'Science en fête', TO_DATE('20030301', 'YYYYMMDD'), TO_DATE('20030630', 'YYYYMMDD'), 'Pierre', 'Ville');

INSERT INTO Projet VALUES (3, 'Nuit du Picolo', TO_DATE('20021101', 'YYYYMMDD'), TO_DATE('20021130', 'YYYYMMDD'), 'Julien', 'Université');

INSERT INTO Tache VALUES (1, 1, 'Dossier financement', TO_DATE('20020901', 'YYYYMMDD'), TO_DATE('20020930', 'YYYYMMDD'));

INSERT INTO Tache VALUES (2, 1, 'Casting', TO_DATE('20020901', 'YYYYMMDD'), TO_DATE('20020930', 'YYYYMMDD'));

INSERT INTO Tache VALUES (3, 1, 'Script', TO_DATE('20020901', 'YYYYMMDD'), TO_DATE('20020930', 'YYYYMMDD'));

INSERT INTO Tache VALUES (4, 1, 'Répétition', TO_DATE('20021001', 'YYYYMMDD'), TO_DATE('20021130', 'YYYYMMDD'));

INSERT INTO Tache VALUES (5, 1, 'Réservation salle', TO_DATE('20020901', 'YYYYMMDD'), TO_DATE('20020915', 'YYYYMMDD'));

INSERT INTO Tache VALUES (6, 1, 'Publicité', TO_DATE('20021101', 'YYYYMMDD'), TO_DATE('20021115', 'YYYYMMDD'));

INSERT INTO Tache VALUES (7, 1, 'Vente billets', TO_DATE('20021115', 'YYYYMMDD'), TO_DATE('20021130', 'YYYYMMDD'));

INSERT INTO Tache VALUES (1, 2, 'Programme', TO_DATE('20030315', 'YYYYMMDD'), TO_DATE('20030415', 'YYYYMMDD'));

INSERT INTO Participe VALUES ('Alain', 1, 1, 'Prospection');

INSERT INTO Participe VALUES ('Nathalie', 1, 1, 'Rédaction');

INSERT INTO Partenaire (Nom) VALUES ('Mairie');

INSERT INTO Partenaire (Nom) VALUES ('Ministère');

INSERT INTO Partenaire (Nom) VALUES ('Association des commerçants');

INSERT INTO Partenaire (Nom, Description) VALUES ('1664', 'Entreprise de fabrication de bière');

INSERT INTO EstAssocie VALUES ('Mairie', 1, 'Financeur');

INSERT INTO EstAssocie VALUES ('Mairie', 2, 'Financeur');

INSERT INTO EstAssocie VALUES ('Ministère', 2, 'Logistique');

INSERT INTO EstAssocie VALUES ('Association des commerçants', 1, 'Publicitaire');

INSERT INTO EstAssocie VALUES ('1664', 3, 'Réduction sur les bières'); commit;

SELECT * FROM Projet;

CREATE SEQUENCE seq_proj START WITH 4;

INSERT INTO Specialite VALUES ('Commerce');

ALTER TABLE Projet MODIFY nom VARCHAR2(35);
INSERT INTO Projet VALUES (seq_proj.NEXTVAL, 'Médiathèque virtuelle', '05102006', '05102007', 'Pierre', 'Commerce');
INSERT INTO Tache VALUES (1, seq_proj.currval, 'Marketing', '22052007', '30072007');
INSERT INTO Tache VALUES (2, 4, 'Prospection', '22052007', '30072007');
INSERT INTO Tache VALUES (3, 4, 'SAV', '22052007', '30072007');

select * from facture;

select * from ligne_fact;

insert into FACTURE(num, client, date_etabli) values( facture_seq.NEXTVAL, 1, to_date('18042002','DDMMYYYY' ) );

insert into LIGNE_FACT(facture, produit, qte) values( facture_seq.CURRVAL, 1, 3 );

select * from facture;

select * from ligne_fact;

rollback;

select * from facture;

select * from ligne_fact;

select * from facture;

select * from ligne_fact;

insert into FACTURE(num, client, date_etabli) values( facture_seq.NEXTVAL, 1, to_date('18042002','DDMMYYYY' ) );

insert into LIGNE_FACT(facture, produit, qte) values( facture_seq.CURRVAL, 1, 1);

select * from facture;

select * from ligne_fact;

commit;

select * from facture;

select * from ligne_fact;

select sum(qte) FROM LIGNE_FACT GROUP BY produit ORDER BY sum(qte) ASC  ;

select sum(t1.qte*t2.prix) FROM produit t2, ligne_fact t1, facture t3 WHERE t3.num=t1.facture AND t2.num=t1.produit GROUP BY (t3.client) ORDER BY t3.client ASC;

select 