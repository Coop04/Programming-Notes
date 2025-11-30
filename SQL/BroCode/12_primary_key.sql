-- Active: 1731173242441@@127.0.0.1@3306@brocode

-- PRIMARY KEY: column must be both unique and not null (a table can contain only one primary key column)

-- adding primary key when creating a table
create table transactions(
    transaction_id int primary key,
    amount decimal(4,2)
);

-- altering a table to add a primary key
alter table transactions
add CONSTRAINT
primary key(transaction_id);

insert into transactions
VALUES  (1, 20.0),
        (2, 30.0),
        (3, 40.0);

select * from TRANSACTIONS;

insert into transactions
values (3,20.0); -- show duplicate entry error

drop table  transactions;