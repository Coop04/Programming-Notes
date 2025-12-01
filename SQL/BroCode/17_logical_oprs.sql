-- Active: 1731173242441@@127.0.0.1@3306@brocode

select * from employees;
alter table employees
add column job varchar(25) after hourly_pay;

select * FROM employees;

update employees
set job = "manager"
where employee_id =1;

update employees
set job = "cashier"
where employee_id =2;

update employees
set job = "cook"
where employee_id =3;

update employees
set job = "cook"
where employee_id =4;

update employees
set job = "assistant manager"
where employee_id =5;

update employees
set job = "janitor"
where employee_id =6;

SELECT * from employees;

-- and operator
-- finding cook hired before 2023 January 5
SELECT first_name, last_name, job, hire_date
from employees
where job = "cook" and hire_date<"2023-01-5";

-- or opereator
SELECT first_name, last_name, job
from employees
where job = "cook" or job="cashier";

-- not operator
SELECT first_name, last_name, job
from employees
where not job = "manager" ; -- or where job!="manager"

-- we can also combine logical operators 
SELECT first_name, last_name, job
from employees
where not job = "manager" and not job = "assistant manager";

-- between : used between a single column (similar to and)
SELECT first_name, last_name, job, hire_date
from employees
where hire_date between "2023-01-5" and "2023-01-07";

-- in : find any values that are within a set
SELECT *
from employees
where job in ("cook","cashier","janitor");