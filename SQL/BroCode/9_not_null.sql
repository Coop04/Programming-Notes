create table products (
    product_id int,
    product_name varchar(25), 
    price DECIMAL(4,2) not null -- value cant be null (since already created this table in last exp don't run)
);

-- to add not null constraints to a table that already exists
alter table products
modify price DECIMAL(4,2) not null;

insert into products
values (104,"hotdog",null); -- shows column price cannot be null (but 0 is acceptable, null is not accepted)

select * from products;