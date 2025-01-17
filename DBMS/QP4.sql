-- Consider the given company database schema
--  Employee (name, ssn, bdate, address, sex, salary, superssn, dnumber, dateofjoin)
--  Department (dname, dnumber, mgrssn, mgrstartdate)
--  Dept_locations (dnumber, dlocation)
--  Project (pname, pnumber, plocation, dnumber)

create table Department(dname varchar(50),dnumber int primary key,mgrssn int,mgrstartdate date);

create table Employee(name varchar(50),ssn int primary key,bdate date,address varchar(50),sex enum('male','female'),salary decimal(10,2),superssn int,dnumber int,foreign key(dnumber) references Department(dnumber),dateofjoin date);

create table Dept_location(dnumber int, foreign key(dnumber) references Department(dnumber),dlocation varchar(50));

create table Project(pname varchar(50),pnumber int primary key,plocation varchar(50),dnumber int,foreign key(dnumber) references Department(dnumber));

--  Create the required tables and perform the following queries
--  a) Retrieve the name and address of all employees who work for the ‘Research’  
-- department.
select e.name,e.address from Employee e join Department d on e.dnumber = d.dnumber where d.dname = 'Research');
--  b) For every project located in ‘Cochin’, list the project  number, the controlling 
-- department number, and the  department manager’s last name, address, and birth date.

--  c) Retrieve the names of all employees who do not have supervisors.
select name from Employee where superssn is null;
--  d) For each department, retrieve the  department number, the number of employees  in 
-- the department, and their average salary
--  e) Create a view which shows the employee name, employee ssn and salary.
--  f) Write a function which show the resulting salaries if every employee  working on the 
-- ‘ProductX’ project is given a 10  percent raise.
delimiter //
create function raise()
returns varchar(50) deterministic
begin
declare sal decimal(10,2);
declare nam varchar(50);
declare id int;
declare msg varchar(50);
select e.salary,e.name,e.ssn into sal,nam,id from Employee e join Project p on p.dnumber = e.dnumber where p.pname = 'ProductX';
update Employee
set salary = sal * 1.10 where ssn =id;
set msg = concat('Salary of ',nam,' is raised to ',sal);
return msg;
end//
delimiter ;
--  g) Write a PL/SQL block to insert those employees who have current salary greater than 
-- 1 Lakh and date of join before 1 january 2010 into the table Level1, who doesnt meet 
-- above criteria are to be inserted into table Level2 using cursor.