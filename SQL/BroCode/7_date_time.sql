-- Active: 1731173242441@@127.0.0.1@3306@brocode
create table test(my_date date, my_time time, my_datetime DATETIME);

select * from test;

insert into test 
VALUES (CURRENT_DATE(), CURRENT_TIME(), NOW()); -- current_date()+1 will be tomorrow

insert into test
VALUES (CURRENT_DATE()-1, CURRENT_TIME()-1, NOW()); -- current_date()-1 will be yesterday

drop table test;