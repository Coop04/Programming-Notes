-- Active: 1731173242441@@127.0.0.1@3306@brocode
SELECT * from employees;

set autocommit = off; -- by default auto commit is on, treansactions are committed automatically
commit; -- when auto commit is turned off we must manually commit

DELETE FROM employees; -- forgot to add a where clause (delete your whole table)

-- if you want to go back 
ROLLBACK;