-- Active: 1731173242441@@127.0.0.1@3306@brocode


-- subquery: a query within another query
--           query(subquery)

-- comparing hourly_pay with average pay
select first_name, last_name, hourly_pay,(select avg(hourly_pay) from employees) as avg
from employees;

-- every employee that hava an avg pay greater than an avg pay
select first_name, last_name, hourly_pay
from employees
where(hourly_pay>(select avg(hourly_pay) from employees));

-- firstname and lastname of every customers that have placed an order
--distinct keyword is used to eliminate duplicate values
select distinct c.first_name, c.last_name 
from transactions t
join customers c
on t.customer_id = c.customer_id;

-- or by using sub query as ------------use IN keyword (not =)
select first_name, last_name
from customers 
where customer_id IN (select distinct customer_id 
                    from transactions
                    where customer_id is not null)

