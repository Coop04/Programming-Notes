-- Create the following tables and perform the queries on it.
--  Employee(eno(pk), ename, designation, address, salary, phoneno, deptno(fk))
--  Department(deptno(pk), dname, dept_head)
--  Project(pno, pname, deptno)

create table Employee(eno int primary key,ename varchar(50),designation varchar(50),address varchar(100),salary decimal(10,2),phoneno varchar(15),deptno int, foreign key(deptno) references Department(deptno));

create table Department(deptno int primary key,dname varchar(50),dept_head varchar(50));

create table Project(pno int primary key,pname varchar(50), deptno int, foreign key(deptno) references Department(deptno));

-- Inserting values into the Department table
INSERT INTO Department (deptno, dname, dept_head) 
VALUES 
(1, 'Computer Science', 'Dr. Smith'),
(2, 'Electrical Engineering', 'John'),
(3, 'Mechanical Engineering', 'Dr. Lee'),
(4, 'Civil Engineering', 'Dr. Davis');

-- Inserting values into the Employee table
INSERT INTO Employee (eno, ename, designation, address, salary, phoneno, deptno)
VALUES
(1001, 'John Doe', 'Software Engineer', '123 Main St, City', 75000.00, '123-456-7890', 1),
(1002, 'Jane Smith', 'Electrical Engineer', '456 Oak St, City', 80000.00, '234-567-8901', 2),
(1003, 'Alice Brown', 'Mechanical Engineer', '789 Pine St, City', 70000.00, '345-678-9012', 3),
(1004, 'Bob White', 'Civil Engineer', '101 Maple St, City', 72000.00, '456-789-0123', 4),
(1005, 'Sob A', 'Civil Engineer', '102 Faple St, City', 73000.00, '456-789-0183', 4);

-- Inserting values into the Project table
INSERT INTO Project (pno, pname, deptno)
VALUES 
(101, 'AI Research', 1),
(102, 'Power Systems', 2),
(103, 'Robotics', 3),
(104, 'Recruitment', 4);

--  a) Display the names of Employees whose name start with S and ends with A.
select ename from Employee where ename like 'S%A';

--  b) Display all employees who works on ‘Recruitment’ project of HR department.
select e.ename from Employee e
join Project p on e.deptno = p.deptno
join Department d on p.deptno = d.deptno
where p.pname = 'Recruitment';

--  c) Display all employees whose department head is ‘John’.
select e.ename from Employee e
join Department d on e.deptno = d.deptno
where dept_head = 'John';

--  d) List all employees who get salary more than ‘Alice Brown’.
select ename from Employee where salary > (select salary from Employee where ename = 'Alice Brown');

--  e) List name and salary of all employees whose salary is greater than salary of all employees working in department number 4.
select e.ename, e.salary from Employee e
join Department d on e.deptno = d.deptno
where salary > (select max(salary) from Employee where deptno = 4); 

--  f) Write a PL/SQL program to raise the salary of all employees of HR department by 20% and R&D by 30%
update Employee e set e.salary = e.salary * 1.2 where e.deptno = 1;
update Employee e set e.salary = e.salary * 1.3 where e.deptno = 3;

--  g) Create a trigger which shows the salary difference of a particular employee whenever salary is getting updated
delimiter //
create trigger salary_diff
before update on Employee
for each row begin
declare diff int;
set diff = new.salary - old.salary;
select concat('Salary Difference: ',diff) as message;
end//
delimiter ; 

--Employee
+------+-------------+---------------------+--------------------+----------+--------------+--------+
| eno  | ename       | designation         | address            | salary   | phoneno      | deptno |
+------+-------------+---------------------+--------------------+----------+--------------+--------+
| 1001 | John Doe    | Software Engineer   | 123 Main St, City  | 75000.00 | 123-456-7890 |      1 |
| 1002 | Jane Smith  | Electrical Engineer | 456 Oak St, City   | 80000.00 | 234-567-8901 |      2 |
| 1003 | Alice Brown | Mechanical Engineer | 789 Pine St, City  | 70000.00 | 345-678-9012 |      3 |
| 1004 | Bob White   | Civil Engineer      | 101 Maple St, City | 72000.00 | 456-789-0123 |      4 |
| 1005 | Sob A       | Civil Engineer      | 102 Faple St, City | 73000.00 | 456-789-0183 |      4 |
+------+-------------+---------------------+--------------------+----------+--------------+--------+
5 rows in set (0.00 sec)

-- Department
+--------+------------------------+-----------+
| deptno | dname                  | dept_head |
+--------+------------------------+-----------+
|      1 | Computer Science       | Dr. Smith |
|      2 | Electrical Engineering | John      |
|      3 | Mechanical Engineering | Dr. Lee   |
|      4 | Civil Engineering      | Dr. Davis |
+--------+------------------------+-----------+
4 rows in set (0.01 sec)

-- Project
+-----+---------------+--------+
| pno | pname         | deptno |
+-----+---------------+--------+
| 101 | AI Research   |      1 |
| 102 | Power Systems |      2 |
| 103 | Robotics      |      3 |
| 104 | Recruitment   |      4 |
+-----+---------------+--------+
4 rows in set (0.01 sec)