-- Question:
-- 1. Create tables for the following relations. Populate the tables with the test cases given to answer the queries:
-- Item(item_id, item_desc, qty_on_hand, unit_price, category, status);
-- Sale(sale_id, sale_date, item_id, qty_sold, unit_price, total_price, tax_amount, grand_total);
-- status (possible values are 'Available' and 'Out of stock'), default value is 'Available'.
-- item_id is the primary key in the Item table and a foreign key in the Sale table.
-- sale_id is the primary key in the Sale table and must be auto-incremented.
-- sale_date should have the data type 'DATE' and use the system date (CURDATE()).
-- 
-- Contents of the Item table
-- | item_id | item_desc | qty_on_hand | unit_price | category   | status       |
-- |---------|-----------|-------------|------------|------------|--------------|
-- | 100     | TextBook  | 0           | 20.00      | book       | Out of stock |
-- | 101     | milkybar  | 30          | 5.00       | chocolate  | Available    |
-- | 102     | apple     | 35          | 10.00      | fruit      | Available    |
-- | 103     | pen       | 87          | 8.00       | stationery | Available    |

-- Contents of the Sale table
-- | sale_id | sale_date   | item_id | qty_sold | unit_price | total_price | tax_amount | grand_total |
-- |---------|-------------|---------|----------|------------|-------------|------------|-------------|
-- | 1       | 2024-11-03  | 100     | 5        | 20.00      | 100.00      | 10.00      | 110.00      |
-- | 2       | 2024-11-03  | 101     | 10       | 5.00       | 50.00       | 10.00      | 60.00       |
-- | 3       | 2024-11-03  | 102     | 3        | 10.00      | 30.00       | 1.50       | 31.50       |
-- | 4       | 2024-11-04  | 103     | 8        | 8.00       | 64.00       | 12.80      | 76.80       |

-- Answer:

-- 1. Create and populate Item and Sale tables
CREATE TABLE Item (
    item_id INT PRIMARY KEY,
    item_desc VARCHAR(100),
    qty_on_hand INT,
    unit_price DECIMAL(10, 2),
    category VARCHAR(50),
    status VARCHAR(20) DEFAULT 'Available'
);

INSERT INTO Item (item_id, item_desc, qty_on_hand, unit_price, category, status)
VALUES 
(100, 'TextBook', 0, 20.00, 'book', 'Out of stock'),
(101, 'milkybar', 30, 5.00, 'chocolate', 'Available'),
(102, 'apple', 35, 10.00, 'fruit', 'Available'),
(103, 'pen', 87, 8.00, 'stationery', 'Available');

CREATE TABLE Sale (
    sale_id INT AUTO_INCREMENT PRIMARY KEY,
    sale_date DATE DEFAULT CURDATE(),
    item_id INT,
    qty_sold INT,
    unit_price DECIMAL(10, 2),
    total_price DECIMAL(10, 2),
    tax_amount DECIMAL(10, 2),
    grand_total DECIMAL(10, 2),
    FOREIGN KEY (item_id) REFERENCES Item(item_id)
);

INSERT INTO Sale (item_id, qty_sold, unit_price, total_price, tax_amount, grand_total)
VALUES 
(100, 5, 20.00, 100.00, 10.00, 110.00),
(101, 10, 5.00, 50.00, 10.00, 60.00),
(102, 3, 10.00, 30.00, 1.50, 31.50),
(103, 8, 8.00, 64.00, 12.80, 76.80);

-- 2. Display date-wise summary of sale including aggregate of 'total price' and 'tax amount'.
SELECT 
    sale_date, 
    SUM(total_price) AS total_price,
    SUM(tax_amount) AS total_tax_amount,
    SUM(grand_total) AS total_grand_total
FROM Sale
GROUP BY sale_date;

-- 3. Display the name of the item with the lowest unit price from the Item table.
SELECT item_desc
FROM Item
WHERE unit_price = (SELECT MIN(unit_price) FROM Item);

-- 4. Display the name of the item which was not purchased by anyone.
SELECT item_desc
FROM Item
WHERE item_id NOT IN (SELECT DISTINCT item_id FROM Sale);

-- 5. Create a view to display the sale_id, item_id, item_desc, and total price.
CREATE VIEW SaleView AS
SELECT 
    sale_id, 
    item_id, 
    (SELECT item_desc FROM Item WHERE Item.item_id = Sale.item_id) AS item_desc,
    total_price
FROM Sale;

-- 6. Create a function to display the quantity available for an item ID.
DELIMITER //
CREATE FUNCTION GetQuantityAvailable(item_id_input INT)
RETURNS INT
DETERMINISTIC
BEGIN
    DECLARE qty INT;
    SELECT qty_on_hand INTO qty
    FROM Item
    WHERE item_id = item_id_input;
    RETURN qty;
END;
//
DELIMITER ;

-- 7. Create a procedure to insert a record in the Sale table. The tax rate for various categories: book (10%), stationery (20%), chocolate (30%), other (5%).
DELIMITER //
CREATE PROCEDURE InsertSale(IN item_id_input INT, IN qty_sold_input INT)
BEGIN
    DECLARE unit_price_input DECIMAL(10, 2);
    DECLARE category_input VARCHAR(50);
    DECLARE tax_rate DECIMAL(5, 2);
    DECLARE total_price_input DECIMAL(10, 2);
    DECLARE tax_amount_input DECIMAL(10, 2);
    DECLARE grand_total_input DECIMAL(10, 2);

    -- Fetch the unit price and category for the given item_id
    SELECT unit_price, category INTO unit_price_input, category_input
    FROM Item
    WHERE item_id = item_id_input;

    -- Set the tax rate based on the category using IF...ELSEIF
    IF category_input = 'book' THEN
        SET tax_rate = 0.10;
    ELSEIF category_input = 'stationery' THEN
        SET tax_rate = 0.20;
    ELSEIF category_input = 'chocolate' THEN
        SET tax_rate = 0.30;
    ELSE
        SET tax_rate = 0.05;
    END IF;

    -- Calculate total price, tax amount, and grand total
    SET total_price_input = unit_price_input * qty_sold_input;
    SET tax_amount_input = total_price_input * tax_rate;
    SET grand_total_input = total_price_input + tax_amount_input;

    -- Insert the new sale record into the Sale table
    INSERT INTO Sale (item_id, qty_sold, unit_price, total_price, tax_amount, grand_total)
    VALUES (item_id_input, qty_sold_input, unit_price_input, total_price_input, tax_amount_input, grand_total_input);
END;
//
DELIMITER ;


-- 8. Create a trigger to update qty_on_hand after a sale and set status to 'Out of stock' if qty_on_hand < 1.
DELIMITER //
CREATE TRIGGER UpdateStockAfterSale
AFTER INSERT ON Sale
FOR EACH ROW
BEGIN
    UPDATE Item
    SET qty_on_hand = qty_on_hand - NEW.qty_sold,
        status = CASE WHEN qty_on_hand - NEW.qty_sold < 1 THEN 'Out of stock' ELSE 'Available' END
    WHERE item_id = NEW.item_id;
END;
//
DELIMITER ;

DELIMITER //

CREATE TRIGGER UpdateStockAfterSale
AFTER INSERT ON Sale
FOR EACH ROW
BEGIN
    DECLARE new_qty_on_hand INT;

    -- Fetch the current qty_on_hand for the item from the Item table
    SELECT qty_on_hand INTO new_qty_on_hand
    FROM Item
    WHERE item_id = NEW.item_id;

    -- Calculate the new qty_on_hand after the sale
    SET new_qty_on_hand = new_qty_on_hand - NEW.qty_sold;

    -- Update the qty_on_hand in the Item table
    UPDATE Item
    SET qty_on_hand = new_qty_on_hand
    WHERE item_id = NEW.item_id;

    -- Check if qty_on_hand is less than 1, update status to 'Out of stock' if true
    IF new_qty_on_hand < 1 THEN
        UPDATE Item
        SET status = 'Out of stock'
        WHERE item_id = NEW.item_id;
    END IF;
END //

DELIMITER ;
