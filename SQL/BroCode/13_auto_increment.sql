-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- can be applied to a column that is a key

-- when creating a table
create table transaction(
    transaction_id int primary key AUTO_INCREMENT, -- by defaylt primary key is set to 1
    amount decimal(5,2)
);

-- to add autoincrement in an existing table
alter table transaction
MODIFY column transaction_id int AUTO_INCREMENT;


select * from transaction;

insert into transaction(amount)
VALUES  (20.0),
        (30.0),
        (40.0);

-- to do auto increment from a specific value in an existing table (which already has autoincrement set up)
alter table transaction
AUTO_INCREMENT = 1000; -- now it will auto increment from 1000 (only one auto increment in a table , so no need to specify the column name)

insert into transaction(amount)
values (40.0),
        (30.0);

-- delete from transaction
-- where transction_id >=1000;

drop Table transaction;