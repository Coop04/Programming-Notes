-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- can be applied to a column that is a key

-- when creating a table
create table transaction(
    transction_id int primary key auto_increment, -- by defaylt primary key is set to 1
    amount decimal(5,2)
);


select * from transaction;

insert into transaction(amount)
VALUES  (20.0),
        (30.0),
        (40.0);

-- to do auto increment in an existing table
alter table transaction
AUTO_INCREMENT = 1000; -- now it will auto increment from 1000

insert into transaction(amount)
values (40.0),
        (30.0);

-- delete from transaction
-- where transction_id >=1000;

drop Table transaction;