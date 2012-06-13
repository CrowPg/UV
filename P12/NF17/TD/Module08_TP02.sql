DROP TABLE INVENTAIRE;
CREATE TABLE INVENTAIRE(
PRODUIT NUMBER,
DESIGNATION VARCHAR(128),
PRIX NUMBER, 
DEMANDE VARCHAR(7) CHECK (DEMANDE IN ('FORTE', 'MOYENNE', 'FAIBLE')),
CONSTRAINT PK_INVENTAIRE PRIMARY KEY (PRODUIT),
FOREIGN KEY(PRODUIT) REFERENCES PRODUIT);

CREATE OR REPLACE FUNCTION fDemande (num_produit in number) RETURN varchar
IS
  qte_vendue NUMBER;
BEGIN
  SELECT SUM(qte)  INTO qte_vendue
  FROM LIGNE_FACT
  WHERE num_produit=LIGNE_FACT.PRODUIT;
  IF qte_vendue>1000 THEN
    RETURN ('FORTE');
  ELSIF qte_vendue>500 THEN
    RETURN ('MOYENNE');
  ELSE RETURN ('FAIBLE');
  END IF ;
END fDemande;
/
SHOW ERRORS;

SELECT t1.NUM, t1.designation, T1.prix, fDemande(t1.NUM) FROM PRODUIT t1;

INSERT INTO INVENTAIRE 
SELECT t1.NUM, t1.designation, T1.prix, fDemande(t1.NUM) FROM PRODUIT t1;

create or replace procedure nb_fact(num_client in number, nb out number, ca out number)
IS 
BEGIN
  SELECT COUNT(*) INTO nb FROM FACTURE WHERE FACTURE.CLIENT=num_client; 
  select sum(t1.qte*t2.prix) INTO ca FROM produit t2, ligne_fact t1, facture t3 WHERE t3.num=t1.facture AND t2.num=t1.produit AND t3.client=num_client;
END;
/

SET SERVEROUTPUT ON;
declare
  client number;
  nb number;
  ca number;
begin
  client:=2;
  nb_fact(client, nb, ca);
  DBMS_OUTPUT.PUT_LINE('nb : ' || nb || ' ca : ' || ca);
end;
/
SET SERVEROUTPUT ON;
DECLARE
  CURSOR c_client IS 
    SELECT NUM FROM CLIENT;
  nb number;
  ca number;
BEGIN
  FOR cli IN c_client LOOP
  -- cli : toute la ligne
    nb_fact(cli.num, nb, ca);
    DBMS_OUTPUT.PUT_LINE('client' || cli.num || ' : ' || 'nb : ' || nb || ' ca : ' || ca);
  END LOOP;
END;
/

create or replace trigger TR_STOCK_AUDIT
after insert on ligne_fact
for each row
declare
  newStock number;
  exceptio exception;
begin
  update PRODUIT
  set stock=stock-:new.qte
  where num=:new.produit;
  select stock into newStock from produit where num=:new.produit;
  if (newstock < 0) then
    RAIsE exceptio;
  Elsif (newstock < 5) then
    INSERT INTO JOURNALISATION VALUES(
      'Le message',
      SYSDATE,
      :new.produit,
      newStock);
  End if;
end;
/

insert into ligne_fact values (2, 4, 4998);

CREATE TABLE journalisation(
message varchar(128),
date_jour date,
produit number,
new_stock number);


select * from journalisation;
