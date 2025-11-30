-- Active: 1731173242441@@127.0.0.1@3306@brocode
select * from employees; -- select every columns

-- selecting specific columns
SELECT first_name, last_name -- can change the order too (the way we like)
from employees;

-- selecting based on a criteria
SELECT * from employees
WHERE employee_id = 4;

select * from employees
where first_name = "Spongbob";

select * from employees
WHERE hourly_pay >= 15;

SELECT * from employees
where hire_date <= "2023-01-03";

select * from employees
where employee_id != 5;

SELECT * from employees
where hire_date is null; -- in case of null, 'is' keyword is used instead of =

SELECT * from employees
where hire_date is not NULL;