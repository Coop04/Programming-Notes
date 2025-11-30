-- Active: 1731173242441@@127.0.0.1@3306@brocode

select * from employees;

-- to update single column value in a table
UPDATE employees
set hourly_pay = 10.25
where employee_id = 6;

-- to update multiple column values
UPDATE employees
set hourly_pay = 10.50, 
    hire_date = "2023-01-07"
where employee_id = 6;

-- to set value to null 
update employees
set hire_date = NULL
where employee_id = 6;

-- to update all the values in a column (don't run it now)
update employees
set hourly_pay = 10.25; -- sets all the values of hourly_pay to (10.25)

-- to delete all rows in your table (don't run now)
delete from employees;

-- to delete specific rows
DELETE from employees
where employee_id = 6;