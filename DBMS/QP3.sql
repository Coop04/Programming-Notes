-- Create Salesdetails table
CREATE TABLE Salesdetails (
    salesman_id INT PRIMARY KEY,
    salesman_name VARCHAR(100),
    quantity INT,
    rate DECIMAL(10, 2),
    date DATE
);

-- Create Salescommission table
CREATE TABLE Salescommission (
    salesman_id INT PRIMARY KEY,
    commission DECIMAL(10, 2),
    FOREIGN KEY (salesman_id) REFERENCES Salesdetails(salesman_id)
);
-- Insert data into Salesdetails
INSERT INTO Salesdetails (salesman_id, salesman_name, quantity, rate, date) VALUES
(1, 'Peter', 10, 200, '2024-11-01'),
(2, 'Paul', 15, 150, '2024-11-02'),
(3, 'Priya', 20, 180, '2024-11-03'),
(4, 'Pooja', 5, 250, '2024-11-04'),
(5, 'Pradeep', 30, 160, '2024-11-05');

-- Insert data into Salescommission
INSERT INTO Salescommission (salesman_id, commission) VALUES
(1, 300),
(2, 400),
(3, 500),
(4, 200),
(5, 350);

-- Create a trigger called ‘givecommission’. Everytime when the quantity column is updated the rate should be updated accordingly and then the trigger checks to see if the total amount of a Salesman is over Rs.1000/- If so, add a commission of Rs.200/- (Rate for a single item is Rs. 150/-)
delimiter //
create trigger givecommissions
before update on Salesdetails 
for each row begin
declare total_amount int;

set new.rate = 150;
set total_amount = new.quantity * new.rate;
if total_amount > 1000 then
    update Salescommission
    set commission = commission + 200
    where salesman_id = new.salesman_id;
end if;
end//
delimiter ;

-- Write a function to retrieve the salesman_name, quantity sold by the salesman and his commission. (input to the function: salesman_id).
delimiter //
create function sales_details(id int)
returns varchar(200)
deterministic
begin
declare name varchar(50);
declare qty int;
declare com double(10,2);
declare msg varchar(200);
select d.salesman_name,d.quantity,c.commission into name,qty,com
from Salesdetails d
join Salescommission c on d.salesman_id = c.salesman_id
where d.salesman_id = id;
set msg = concat('Name: ',name,', Quantity Sold: ',qty,', Commission: ',com);
return msg;
end//
delimiter ;

mysql> select * from Salesdetails; 
+-------------+---------------+----------+--------+------------+
| salesman_id | salesman_name | quantity | rate   | date       |
+-------------+---------------+----------+--------+------------+
|           1 | Peter         |       10 | 200.00 | 2024-11-01 |
|           2 | Paul          |       15 | 150.00 | 2024-11-02 |
|           3 | Priya         |       20 | 180.00 | 2024-11-03 |
|           4 | Pooja         |        5 | 250.00 | 2024-11-04 |
|           5 | Pradeep       |       30 | 160.00 | 2024-11-05 |
+-------------+---------------+----------+--------+------------+

mysql> select * from Salescommission; 
+-------------+------------+
| salesman_id | commission |
+-------------+------------+
|           1 |     300.00 |
|           2 |     400.00 |
|           3 |     500.00 |
|           4 |     200.00 |
|           5 |     350.00 |
+-------------+------------+