-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- union: combines the results of 2 or more select statements
-- the combining results must have same number  of columns

-- union all: also incudes duplicates if more than one value is found within each table

CREATE TABLE income (
    income_name VARCHAR(50),
    amount DECIMAL(10,2)
);

INSERT INTO income (income_name, amount) VALUES
('orders', 100000.00),
('merchandise', 50000.00),
('services', 125000.00);

CREATE TABLE expenses (
    expense_name VARCHAR(50),
    amount DECIMAL(10,2)
);

INSERT INTO expenses (expense_name, amount) VALUES
('wages', -250000.00),
('tax', -50000.00),
('repairs', -15000.00);

SELECT * FROM expenses;

SELECT * FROM income;


-- if we want to disply the both as a single table
SELECT * FROM income 
union
SELECT * FROM expenses;

drop table income;
drop Table expenses;

-- -----------------------------------------

-- to make a list of all employess and customers that enters the store 
select * from employees;

select * from customers;
-- here both tables have different number of rows so direct use of union will not work
-- we must make the number of columns similar

select first_name, last_name from employees
UNION
select first_name, last_name from customers

-- union all: also incudes duplicates if more than one value is found within each table
-- just for example lets insert plankton into customers table 

insert into customers
values (5,"Sheldon", "Plankton");

select * from customers;
SELECT* from employees;

select first_name, last_name from employees
UNION -- only shows 1 Sheldon Plankton (ie, no duplicates)
select first_name, last_name from customers;

select first_name, last_name from employees
UNION ALL -- shows 2 Sheldon Planktons
select first_name, last_name from customers;

DELETE from customers
where first_name = "Sheldon";
select * from customers;