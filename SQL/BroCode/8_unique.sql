-- Active: 1731173242441@@127.0.0.1@3306@brocode
create table products (
    product_id int,
    product_name varchar(25) UNIQUE, -- when using unique key word we cannot insert same values twice, all must be different
    price DECIMAL(4,2)
);

select * from products;

-- if you forgot to add unique when creating a product
alter table products
add CONSTRAINT UNIQUE(product_name);

insert into products
values (100,"hamburger",3.99),
       (101,"fries",1.89),
       (102,"soda",1.00),
       (103,"ice cream",1.49);
       --(104,"fries",1.79);  -- shows duplicate error