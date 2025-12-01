-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- when inserting a new row if we do not specify a value for a column we can provide it a default value

SELECT * from products;

-- when creating new table with default (dont do this now , since we already have the table)
create table products ( 
    product_id int,
    priduct_name VARCHAR(25),
    price DECIMAL(4,2) DEFAULT 0
);

-- alter a table to add default values
alter table products
alter price set default 0; -- or use MODIFY column price int default 0;

insert into products (product_id, product_name) -- when only inserting partial date remember to add column names along with the table name
values (104, "napkin"),
        (105, "straw"),
        (106, "spoon"),
        (107, "fork");

create table transaction (
    transcation_id INT,
    transaction_date DATETIME default now()
);

insert into transaction (transcation_id)
VALUES  (1),
        (2),
        (3),
        (4);

select * from transaction;

insert into transaction(transcation_id)
values (5);

drop table TRANSACTION;