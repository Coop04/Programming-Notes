-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- joins: clause that is used to combine rows from 2 or more tables based on a related column between the such as a foreign key

INSERT INTO transactions (amount, customer_id)
VALUES (1.00, NULL); -- foreign key (customer_id) can be null

SELECT * FROM transactions;

INSERT INTO customers (first_name, last_name)
VALUES ("Poppy", "Puff");

SELECT * FROM customers;


-- INNER JOIN : select all rows from these 2 tables that have matching customer ids
select * 
from transactions -- this is going to be the left TABLE
inner join customers -- right table 
on transactions.customer_id = customers.customer_id; -- foreign key column

-- you can also selct specific columns (can be done in left join and right join)
select transaction_id, amount, first_name, last_name
from transactions -- this is going to be the left TABLE
inner join customers -- right table 
on transactions.customer_id = customers.customer_id; -- foreign key column

-- LEFT JOIN: display everything from the table on the left
select *
from transactions -- this is going to be the left TABLE
left join customers -- right table 
on transactions.customer_id = customers.customer_id; -- foreign key column

-- RIGHT JOIN: display everything from the table on the right
select *
from transactions -- this is going to be the left TABLE
right join customers -- right table 
on transactions.customer_id = customers.customer_id; 