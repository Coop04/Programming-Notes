-- when update or insert is done in a trigger is in the same table given in (on tablename) then before is used if op. is done in another table after is used (typically true)

Create tables based on the following schema
Item(item_id,item_desc,qty_on_hand,unit_price,category);
Sales(sale_id,item_id,qty_sold, unit_price, total_price, tax_amount,grand_total);
item_id is primary key in Item table and item_id is foreign key in Sales table.
sale_id is primary key in Sales table.
    i. Create trigger for calculating total_price, tax_amount and grand_total in sales table while inserting values.
	The tax rate of vaious category as shown below.
book (10%)
stationery (20%)
chocolate (30%)
other (5%)
    ii. Create a trigger to calculate the stock of an Item after sales of an Item.
select * from Item;

+---------+-----------+-------------+------------+------------+

| item_id | item_desc | qty_on_hand | unit_price | category   |

+---------+-----------+-------------+------------+------------+

|     100 | TextBook  |          20 |         20 | book       |

|     101 | milkybar  |          30 |          5 | chocolate  |

|     102 | apple     |          50 |         10 | fruit      |

|     103 | pen       |         100 |          8 | stationery |

+---------+-----------+-------------+------------+------------+

4 rows in set (0.00 sec)

insert into Sales(sale_id,item_id,qty_sold) values(200,100,10);

insert into Sales(sale_id,item_id,qty_sold) values(201,101,25);

insert into Sales(sale_id,item_id,qty_sold) values(202,102,10);

insert into Sales(sale_id,item_id,qty_sold) values(203,103,20);

 select * from Sales;

+---------+---------+----------+------------+-------------+------------+-------------+

| sale_id | item_id | qty_sold | unit_price | total_price | tax_amount | grand_total |

+---------+---------+----------+------------+-------------+------------+-------------+

|     200 |     100 |       10 |         20 |         200 |         20 |         220 |

|     201 |     101 |       25 |          5 |         125 |         38 |         163 |

|     202 |     102 |       10 |         10 |         100 |          5 |         105 |

|     203 |     103 |       20 |          8 |         160 |         32 |         192 |

+---------+---------+----------+------------+-------------+------------+-------------+

4 rows in set (0.00 sec)



select * from Item;

+---------+-----------+-------------+------------+------------+

| item_id | item_desc | qty_on_hand | unit_price | category   |

+---------+-----------+-------------+------------+------------+

|     100 | TextBook  |          10 |         20 | book       |

|     101 | milkybar  |           5 |          5 | chocolate  |

|     102 | apple     |          40 |         10 | fruit      |

|     103 | pen       |          80 |          8 | stationery |

+---------+-----------+-------------+------------+------------+

-- 1. Create the Item table
CREATE TABLE Item (
    item_id INT PRIMARY KEY,
    item_desc VARCHAR(50),
    qty_on_hand INT,
    unit_price DECIMAL(10, 2),
    category VARCHAR(20)
);

-- 2. Create the Sales table
CREATE TABLE Sales (
    sale_id INT PRIMARY KEY,
    item_id INT,
    qty_sold INT,
    unit_price DECIMAL(10, 2),
    total_price DECIMAL(10, 2),
    tax_amount DECIMAL(10, 2),
    grand_total DECIMAL(10, 2),
    FOREIGN KEY (item_id) REFERENCES Item(item_id)
);

-- 3. Create a trigger for calculating total_price, tax_amount, and grand_total in the Sales table while inserting values
DELIMITER //
CREATE TRIGGER calculate_sales_totals
BEFORE INSERT ON Sales
FOR EACH ROW
BEGIN
    -- Fetch the unit price and category from Item table
    DECLARE unit_price DECIMAL(10, 2);
    DECLARE category VARCHAR(20);
    DECLARE tax_rate DECIMAL(5, 2);

-- when new item is being added the unit_price and category will be loaded into the parameters declared inside the trigger
    SELECT unit_price, category INTO unit_price, category
    FROM Item
    WHERE item_id = NEW.item_id;

    -- Assign tax rates based on the category
    IF category = 'book' THEN
        SET tax_rate = 0.10;
    ELSEIF category = 'stationery' THEN
        SET tax_rate = 0.20;
    ELSEIF category = 'chocolate' THEN
        SET tax_rate = 0.30;
    ELSE
        SET tax_rate = 0.05;
    END IF;

    -- Set the unit price for the sale
    SET NEW.unit_price = unit_price;

    -- Calculate total_price, tax_amount, and grand_total
    SET NEW.total_price = NEW.qty_sold * unit_price;
    SET NEW.tax_amount = NEW.total_price * tax_rate;
    SET NEW.grand_total = NEW.total_price + NEW.tax_amount;
END//
DELIMITER ;

-- 4. Create a trigger to calculate the stock of an Item after sales of an Item
DELIMITER //
CREATE TRIGGER update_stock_after_sale
AFTER INSERT ON Sales
FOR EACH ROW
BEGIN
    -- Update the stock in the Item table
    UPDATE Item
    SET qty_on_hand = qty_on_hand - NEW.qty_sold
    WHERE item_id = NEW.item_id;
END//
DELIMITER ;

-- 5. Insert records into the Item table
INSERT INTO Item (item_id, item_desc, qty_on_hand, unit_price, category)
VALUES
    (100, 'TextBook', 20, 20, 'book'),
    (101, 'milkybar', 30, 5, 'chocolate'),
    (102, 'apple', 50, 10, 'fruit'),
    (103, 'pen', 100, 8, 'stationery');

-- 6. Insert records into the Sales table
INSERT INTO Sales (sale_id, item_id, qty_sold)
VALUES
    (200, 100, 10),
    (201, 101, 25),
    (202, 102, 10),
    (203, 103, 20);

-- 7. Select all from the Item table after insertions
SELECT * FROM Item;

-- 8. Select all from the Sales table after insertions
SELECT * FROM Sales;
