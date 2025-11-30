-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- FOREIGN KEY: primary key from one table that can be found within a different table
-- using a foreign key we can establis a link between 2 tables

CREATE TABLE customers (
    customer_id INT PRIMARY KEY AUTO_INCREMENT,
    first_name VARCHAR(50),
    last_name VARCHAR(50)
);

INSERT INTO customers (first_name, last_name)
VALUES
    ("Fred", "Fish"),
    ("Larry", "Lobster"),
    ("Bubble", "Bass");


SELECT * FROM customers;

-- creating foreign key when creating table
CREATE TABLE transactions (
    transaction_id INT PRIMARY KEY AUTO_INCREMENT,
    amount DECIMAL(5, 2),
    customer_id INT,
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);

select * from transactions;

-- can also give foreign key a unique name
alter table transactions
add CONSTRAINT fk_customer_id
foreign key(customer_id) REFERENCES customers(customer_id);

-- to drop a foreign key
-- alter table transactions
-- drop FOREIGN key fk_customer_id;

delete from transactions;
select * from transactions;

alter table transactions 
AUTO_INCREMENT = 1000;

INSERT INTO transactions (amount, customer_id)
VALUES
    (4.99, 3),
    (2.89, 2),
    (3.38, 3),
    (4.99, 1);


-- benifits
-- joining 
-- we now have a link between 2 tables, sql will prevent any actions that would destroy that link, unless we explicitly drop the foreign key constraint

DELETE from customers 
where customer_id = 3; -- cannot delete (because of the link)