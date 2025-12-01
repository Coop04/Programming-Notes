-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- wild card characters: % _
-- used to substitute one or more characters in a string

select * from employees;

-- to find employees starting with an S
select * from employees
where first_name like "S%";

-- last names ending with s
select * from employees
where last_name like "%s";

-- to select name containing a substring
select * from employees
where last_name like "%ee%";

-- name starting with Sp
select * from employees
where first_name like "sp%"; -- case of the characters doesnt matter (no need of Sp%)

-- to find name with specific 2nd letter
select * from employees
where first_name like "_po%";

-- hire date in january
select * from employees
where hire_date like "____-01%";

-- hire date is january 4
select * from employees
where hire_date like "____-__-04";

