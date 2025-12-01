-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- order by: sorts the results of a query in either ascending or descending order
-- default ascending 
-- desc for descending order (asc for ascending order, not needed)

select * FROM employees;

-- listing employee names alphabetically
SELECT * from employees
order by first_name; -- ascending order by default

SELECT * from employees
order by first_name desc; -- for descending order

SELECT * from employees
order by hire_date desc;

-- ------------------------------

select * from transactions;

select * from transactions
order by amount asc, customer_id asc; --if 2 values are same we can add an additional constraint to order by
-- here if 2 orders are same, it will sort them on the basis of customer_id
-- default is ascending for both (specify order only of needed)