-- Active: 1731173242441@@127.0.0.1@3306@brocode

CREATE TABLE employees (
    employee_id INT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    hourly_pay DECIMAL(5,2), -- first value is the maximum number of digits, and 2nd is the precision (no.s after decimal)
    hire_date DATE
)

-- select your table
SELECT * FROM employees;

-- to rename a table
RENAME TABLE employees TO workers;
RENAME TABLE workers TO employees;

-- to drop a table
DROP TABLE employees; -- we need the table so dont execute

-- to alter a table
ALTER TABLE employees 
ADD column phone_number VARCHAR(15);

-- to rename a column
ALTER TABLE employees
RENAME COLUMN phone_number to email;


-- Use MODIFY when you want to change the definition of an existing column.
-- ------------------------------------------------------------------------
-- to change the datatype of a column
ALTER TABLE employees
MODIFY COLUMN email VARCHAR(100);

-- if you need to move the column to first
ALTER Table employees
modify COLUMN email varchar(100)
FIRST;

-- to change the position of a column
ALTER TABLE employees
MODIFY email VARCHAR(100)
AFTER last_name;


-- to drop a column
ALTER table employees
drop COLUMN email;