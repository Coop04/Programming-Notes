-- Create an Employee table for the following fields
-- (Empno, Empname, Empaddress, salary, dept)
-- Calculate the total of the salary field
-- List the count of employees who have salary less than 50000
-- Find the details of employee having maximum salary
-- Add a new field title to the employee table with a default value as junior software engineer
-- Update the title of employee whose employee number 2004 to "Senor software engineer"
-- Delete the employee record of employee whose emplyee number is 2005


-- DDL : CREATE TABLE (VALUES), ALTER TABLE (ADD), DROP TABLE
-- DML : INSERT, UPDATE (SET), DELETE
-- DQL : SELECT
-- DCL : GRANT, REVOKE

CREATE TABLE Employee (
    Empno INT PRIMARY KEY,
    Empname VARCHAR(100),
    Empaddress VARCHAR(255),
    salary DECIMAL(10, 2),
    dept VARCHAR(50)
);
INSERT INTO Employee (Empno, Empname, Empaddress, salary, dept) VALUES 
(2001, 'Hari', 'Palakkad', 30000, 'Research'),
(2002, 'Devi', 'Kasaragod', 40000, 'Network'),
(2003, 'Gupta', 'Kannur', 50000, 'System Admin'),
(2004, 'Ravi', 'Calicut', 60000, 'HR'),
(2005, 'Rani', 'Calicut', 70000, 'HR');
SELECT * FROM Employee;


SELECT SUM(salary) AS total_salary FROM Employee;

SELECT COUNT(*) AS employee_count FROM Employee WHERE salary < 50000;

SELECT * FROM Employee WHERE salary = (SELECT MAX(salary) FROM Employee);

ALTER TABLE Employee ADD title VARCHAR(100) DEFAULT 'Junior Software Engineer';
SELECT * FROM Employee;

UPDATE Employee SET title = 'Senior Software Engineer' WHERE Empno = 2004;
SELECT * FROM Employee;

DELETE FROM Employee WHERE Empno = 2005;
SELECT * FROM Employee;