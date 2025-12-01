-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- counting number of rows (count)
select count(amount) -- counts how many rows are within that column (null values are not counted, so only the no. of transactions will be there, but if you give transaction_id , even if it have null value feor amount in a row , it will still count)
from transactions; -- can also add a where clause

select count(amount) as "today's transactions" -- use as to rename a column
from transactions

-- finding max value of a column (max)
select max(amount) as MAXIMUM
from transactions;

-- finding minimum (min)
select min(amount) as MINIMUM
from transactions;

-- average
select avg(amount) as average
from transactions;

-- sum of a column (sum)
select sum(amount) as total_amount
from transactions;

-- concatinating 
select * from employees;

select concat(first_name," ",last_name) as full_name
from employees