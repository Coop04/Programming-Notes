-- The schema of book store database is as follows
-- customer (cust_id, cust_name, cust_phone)
-- book (book_id, title, auth_name, unit_price, pub_name, pub_year)
-- sale (sale_id, cust_id, book_id, order_date, quantity)
-- author(auth_name,	country)
-- publisher(pub_name, pub_addr)
-- first attribute in each table is the primary key, foreign keys have same name as primary key.

-- TEST CASES

-- +---------+-----------+------------+

-- | cust_id | cust_name | cust_phone |

-- +---------+-----------+------------+

-- |     100 | hari      |      12345 |

-- |     101 | john      |      23456 |

-- |     102 | ali       |      34567 |

-- +---------+-----------+------------+

-- +-----------+---------+

-- | auth_name | country |

-- +-----------+---------+

-- | Brown     | US      |

-- | Forouzan  | US      |

-- | Navathe   | India   |

-- | Samantha  | India   |

-- | Tanenbaum | US      |

-- | V Prasad  | India   |

-- +-----------+---------+

-- +----------+----------+

-- | pub_name | pub_addr |

-- +----------+----------+

-- | Pearson  | London   |

-- | PHI      | Delhi    |

-- | TMH      | UP       |

-- +----------+----------+

-- +---------+--------+-----------+------------+----------+----------+

-- | book_id | title  | auth_name | unit_price | pub_name | pub_year |

-- +---------+--------+-----------+------------+----------+----------+

-- |    2001 | DS     | Samantha  |        500 | PHI      |     2020 |

-- |    2002 | CP     | V Prasad  |        300 | TMH      |     2019 |

-- |    2003 | DBMS   | Navathe   |        900 | Pearson  |     2018 |

-- |    2004 | DC     | Forouzan  |        700 | TMH      |     2021 |

-- |    2005 | CN     | Tanenbaum |        800 | Pearson  |     2018 |

-- |    2006 | Python | Brown     |        800 | TMH      |     2021 |

-- +---------+--------+-----------+------------+----------+----------+

-- +---------+---------+---------+------------+----------+

-- | sale_id | cust_id | book_id | order_date | quantity |

-- +---------+---------+---------+------------+----------+

-- |     301 |     100 |    2001 | 2021-01-02 |        3 |

-- |     302 |     100 |    2002 | 2019-04-02 |        4 |

-- |     303 |     100 |    2003 | 2019-04-02 |        2 |

-- |     304 |     101 |    2002 | 2021-05-02 |        2 |

-- |     305 |     101 |    2005 | 2021-05-02 |        1 |

-- |     306 |     102 |    2006 | 2022-01-02 |        2 |

-- +---------+---------+---------+------------+----------+

CREATE TABLE customer (
    cust_id INT PRIMARY KEY,
    cust_name VARCHAR(50),
    cust_phone VARCHAR(15)
);

CREATE TABLE author (
    auth_name VARCHAR(50) PRIMARY KEY,
    country VARCHAR(50)
);

CREATE TABLE publisher (
    pub_name VARCHAR(50) PRIMARY KEY,
    pub_addr VARCHAR(100)
);

CREATE TABLE book (
    book_id INT PRIMARY KEY,
    title VARCHAR(100),
    auth_name VARCHAR(50),
    unit_price DECIMAL(10, 2),
    pub_name VARCHAR(50),
    pub_year INT,
    FOREIGN KEY (auth_name) REFERENCES author(auth_name),
    FOREIGN KEY (pub_name) REFERENCES publisher(pub_name)
);

CREATE TABLE sale (
    sale_id INT PRIMARY KEY,
    cust_id INT,
    book_id INT,
    order_date DATE,
    quantity INT,
    FOREIGN KEY (cust_id) REFERENCES customer(cust_id),
    FOREIGN KEY (book_id) REFERENCES book(book_id)
);
INSERT INTO customer (cust_id, cust_name, cust_phone) VALUES 
(100, 'hari', '12345'),
(101, 'john', '23456'),
(102, 'ali', '34567');

INSERT INTO author (auth_name, country) VALUES 
('Brown', 'US'),
('Forouzan', 'US'),
('Navathe', 'India'),
('Samantha', 'India'),
('Tanenbaum', 'US'),
('V Prasad', 'India');

INSERT INTO publisher (pub_name, pub_addr) VALUES 
('Pearson', 'London'),
('PHI', 'Delhi'),
('TMH', 'UP');

INSERT INTO book (book_id, title, auth_name, unit_price, pub_name, pub_year) VALUES 
(2001, 'DS', 'Samantha', 500, 'PHI', 2020),
(2002, 'CP', 'V Prasad', 300, 'TMH', 2019),
(2003, 'DBMS', 'Navathe', 900, 'Pearson', 2018),
(2004, 'DC', 'Forouzan', 700, 'TMH', 2021),
(2005, 'CN', 'Tanenbaum', 800, 'Pearson', 2018),
(2006, 'Python', 'Brown', 800, 'TMH', 2021);

INSERT INTO sale (sale_id, cust_id, book_id, order_date, quantity) VALUES 
(301, 100, 2001, '2021-01-02', 3),
(302, 100, 2002, '2019-04-02', 4),
(303, 100, 2003, '2019-04-02', 2),
(304, 101, 2002, '2021-05-02', 2),
(305, 101, 2005, '2021-05-02', 1),
(306, 102, 2006, '2022-01-02', 2);

-- i. Calculate the sales for a financial year 2021-22? 
SELECT SUM(b.unit_price * s.quantity) AS total_sales
FROM sale s
JOIN book b ON s.book_id = b.book_id
WHERE s.order_date BETWEEN '2021-04-01' AND '2022-03-31';

-- ii. Display publisher wise total price of books published, except for a particular publisher PHI
SELECT b.pub_name, SUM(b.unit_price) AS total_price
FROM book b
WHERE b.pub_name <> 'PHI'
GROUP BY b.pub_name;

-- iii. Write the SQL Query to Find the publisher wise total price of books published
SELECT b.pub_name, SUM(b.unit_price) AS total_price
FROM book b
GROUP BY b.pub_name;

-- iv. Write the SQL Query to display the name of the customer and title of the books purchased by them.
SELECT c.cust_name, b.title
FROM customer c
JOIN sale s ON c.cust_id = s.cust_id
JOIN book b ON s.book_id = b.book_id;

-- v.Find the title of books with author name and country published in year 2021;
SELECT b.title, b.auth_name, a.country
FROM book b
JOIN author a ON b.auth_name = a.auth_name
WHERE b.pub_year = 2021;

-- vi. Get the titles and author name of all books written by authors not living in india.
SELECT b.title, b.auth_name
FROM book b
JOIN author a ON b.auth_name = a.auth_name
WHERE a.country <> 'India';

-- vii.Write the SQL Query to display the cusomer ids and the total quantity of books purchased by them in the decreasing order of total quantity purcased.
SELECT s.cust_id, SUM(s.quantity) AS total_quantity
FROM sale s
GROUP BY s.cust_id
ORDER BY total_quantity DESC;
