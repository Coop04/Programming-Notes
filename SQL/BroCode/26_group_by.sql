-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- group by: aggregate all rows by a specific column
--           often used with aggregate functions
--           eg. sum(), max(), min(), avg(), count()

select * from transactions;

alter table transactions
add COLUMN order_date date;

update transactions 
set order_date = "2023-01-01"
where transaction_id = 1000;

update transactions 
set order_date = "2023-01-01"
where transaction_id = 1001;

update transactions 
set order_date = "2023-01-02"
where transaction_id = 1002;

update transactions 
set order_date = "2023-01-02"
where transaction_id = 1003;

update transactions 
set order_date = "2023-01-03"
where transaction_id = 1004;

INSERT INTO transactions (amount, customer_id, order_date)
VALUES 
    (2.49, 4, '2023-01-03'),
    (5.48, null, '2023-01-03');


-- how much money we made per day
select order_date, sum(amount) as sum 
from transactions
GROUP BY order_date;

-- max amount on each days
select order_date, max(amount) as max
from transactions
GROUP BY order_date;

-- money spent by each customer in descending order
select customer_id, sum(amount) as sum
from transactions
GROUP BY customer_id
order by sum desc;

-- amount of times each customer ordered
select customer_id, count(amount) as times
from transactions
GROUP BY customer_id
order by times desc;

-- using a where clause with groupby doestn usually work
select customer_id, count(amount) as times
from transactions
GROUP BY customer_id
where count(amount)>1; -- will cause error, use HAVING instead of WHERE

select customer_id, count(amount) as times
from transactions
GROUP BY customer_id
having count(amount)>1;

select customer_id, count(amount) as times
from transactions
GROUP BY customer_id
having count(amount)>1 and customer_id is not null;