-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- self join (we can use inner, left or right join according to need)

-- join another copy of a table to itself
-- used to compare rows of the same table
-- helps to display a heirarchy of data

select * from customers;

alter table customers
add column referral_id int;

select * from customers;

update customers 
set referral_id = 1
where customer_id = 2;

update customers 
set referral_id = 2
where customer_id = 3;

update customers 
set referral_id = 2
where customer_id = 4;

-- update customers 
-- set referral_id = 2
-- where customer_id = 3 and customer_id = 4; this can't be done (because a single row cannot have customer_id equal to 3 AND 4 at the same time, so 0 rows match, and nothing gets updated.)

-- we can either do 2 update statements like above or use IN 
-- UPDATE customers
-- SET referral_id = 2
-- WHERE customer_id IN (3, 4);


-- self join using inner join
select * 
from customers as a
inner JOIN customers as b
on a.referral_id = b.customer_id; 
-- here the referal id of table a is linked with referal id of table b

-- selecting only specific columns
select a.customer_id, a.first_name, a.last_name,
       CONCAT(b.first_name," ", b.last_name) as referred_by
from customers as a
inner JOIN customers as b
on a.referral_id = b.customer_id; 
-- here the referal id of table a is linked with referal id of table b

-- self join using left join
SELECT a.customer_id, a.first_name, a.last_name,
       CONCAT(b.first_name, " ", b.last_name) AS "referred_by"
FROM customers AS a
LEFT JOIN customers AS b
ON a.referral_id = b.customer_id;

-- self join using right join
SELECT a.customer_id, a.first_name, a.last_name,
       CONCAT(b.first_name, " ", b.last_name) AS "referred_by"
FROM customers AS a
RIGHT JOIN customers AS b
ON a.referral_id = b.customer_id;

-- -----------------------------------------------------

select * from employees;

ALTER TABLE employees
ADD supervisor_id INT;

UPDATE employees
SET supervisor_id = 5
where employee_id = 2;

UPDATE employees
SET supervisor_id = 5
where employee_id = 3;

UPDATE employees
SET supervisor_id = 5
where employee_id = 4;

UPDATE employees
SET supervisor_id = 5
where employee_id = 6;

UPDATE employees
SET supervisor_id = 1
where employee_id = 5;

select a.first_name, a.last_name,
        concat(b.first_name," ",b.last_name) as supervised_by
from employees as a  
inner join employees as b
on a.supervisor_id = b.employee_id;

select a.first_name, a.last_name,
        concat(b.first_name," ",b.last_name) as supervised_by
from employees as a  
left join employees as b
on a.supervisor_id = b.employee_id;