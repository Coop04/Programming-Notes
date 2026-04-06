-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- limit clause is used to limit the number of records. 
-- useful if you are working with a number of data
-- can be used to display a large dataset on different pages (pagination)

select * from customers;

select * from customers
limit 3; -- limits the number of data displayed

-- we can also use index too (index starts from 0)
select * from customers
limit 1 offset 2; -- offset means index

select * from customers
limit 2 offset 2; -- gives 2 customers(limit) from index 2((offset) ie, the 3rd customer)

-- eg selecting a value after sorting (order by)
select * from customers
order by last_name limit 1;

select * from customers
order by last_name desc limit 1;