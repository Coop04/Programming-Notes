-- Active: 1731173242441@@127.0.0.1@3306@brocode
CREATE TABLE employees ( -- table already created
    employee_id INT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    hourly_pay DECIMAL(5,2), 
    hire_date DATE
    check (hourly_pay >= 10.0) -- just ckeck will work, but we can also give the check a name
);
CREATE TABLE employees ( -- table already created
    employee_id INT,
    first_name VARCHAR(50),
    last_name VARCHAR(50),
    hourly_pay DECIMAL(5,2), 
    hire_date DATE
    constraint chk_hourly_pay check (hourly_pay >= 10.0) -- just ckeck will work, but we can also give the check a name
);

-- to add a check constraint to a table that already exists
alter TABLE employees
add CONSTRAINT chk_hourly_pay check(hourly_pay>=10.0);

select * from employees;

insert into employees
VALUES(6,"Sheldon","Plankton",5.00,"2023-01-07"); -- will say check constraint chk_hourly_pay violated

insert into employees
VALUES(6,"Sheldon","Plankton",10.00,"2023-01-07"); -- this will work

-- to delete a check
alter Table employees
drop CHECK chk_hourly_pay;