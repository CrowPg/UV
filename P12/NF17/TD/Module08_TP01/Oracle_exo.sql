CREATE TABLE EMPLOYEE
(ID NUMBER(7), LAST_NAME VARCHAR2(25), FIRST_NAME VARCHAR2(25), DEPT_ID NUMBER(7));
DESCRIBE EMPLOYEE;
SELECT * FROM USER_TABLES;
ALTER TABLE EMPLOYEE
MODIFY LAST_NAME VARCHAR2(50);
ALTER TABLE EMPLOYEE ADD CONSTRAINT PK_EMPLOYEE PRIMARY KEY (ID);
SELECT * FROM USER_CONSTRAINTS;
ALTER TABLE EMPLOYEE
ADD SALARY NUMBER(7,7);
ALTER TABLE EMPLOYEE RENAME TO EMPLOYEE2;
DROP TABLE EMPLOYEE2;