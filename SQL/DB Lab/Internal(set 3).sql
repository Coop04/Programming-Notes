-- 1. Create tables for the following relations. Populate the tables with the test cases given to answer the queries:
--    - book (book_id, title, publisher_name) // book_id is PK
--    - student (student_id, name)
--    - book_issue (issue_id, date_of_issue, book_id, student_id, expected_date_of_return, status) 
--      // issue_id is PK and it must be incremented automatically (use AUTO_INCREMENT). book_id and student_id are FK, status attribute values are 'Issued' or 'Returned'.
--    - book_return (issue_id, actual_date_of_return, latedays, latefee) // issue_id is PK and FK

--    **Test Data:**
--    book:
--    - book_id 201, title "DS", publisher_name "PHI"
--    - book_id 202, title "CP", publisher_name "TMH"
--    - book_id 203, title "DBMS", publisher_name "Pearson"
--    - book_id 204, title "DC", publisher_name "TMH"

--    student:
--    - student_id 101, name "Hari"
--    - student_id 102, name "John"
--    - student_id 103, name "Ali"

--    book_issue:
--    - issue_id 1, date_of_issue "2024-11-07", book_id 201, student_id 101, expected_date_of_return "2024-11-21", status "Issued"
--    - issue_id 2, date_of_issue "2024-11-07", book_id 202, student_id 102, expected_date_of_return "2024-11-21", status "Issued"
--    - issue_id 3, date_of_issue "2024-11-07", book_id 203, student_id 103, expected_date_of_return "2024-11-21", status "Issued"

--    book_return:
--    - issue_id 1, actual_date_of_return "2024-11-09"
--    - issue_id 2, actual_date_of_return "2024-12-04"
--    - issue_id 3, actual_date_of_return "2024-12-04"

-- Creating the tables

-- Table for books
CREATE TABLE book (
    book_id INT PRIMARY KEY AUTO_INCREMENT,
    title VARCHAR(255),
    publisher_name VARCHAR(255)
)auto_increment=201;

-- Table for students
CREATE TABLE student (
    student_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(255)
)auto_increment=101;

-- Table for book issue details
CREATE TABLE book_issue (
    issue_id INT PRIMARY KEY AUTO_INCREMENT,
    date_of_issue DATE,
    book_id INT,
    student_id INT,
    expected_date_of_return DATE,
    status ENUM('Issued', 'Returned'),
    FOREIGN KEY (book_id) REFERENCES book(book_id),
    FOREIGN KEY (student_id) REFERENCES student(student_id)
);

-- Table for book return details
CREATE TABLE book_return (
    issue_id INT PRIMARY KEY,
    actual_date_of_return DATE,
    latedays INT,
    latefee INT,
    FOREIGN KEY (issue_id) REFERENCES book_issue(issue_id)
);

-- Inserting test data into the book table
INSERT INTO book (title, publisher_name) VALUES
('DS', 'PHI'),
('CP', 'TMH'),
('DBMS', 'Pearson'),
('DC', 'TMH');

-- Inserting test data into the student table
INSERT INTO student (name) VALUES
('Hari'),
('John'),
('Ali');

-- Inserting test data into the book_issue table
INSERT INTO book_issue (date_of_issue, book_id, student_id, expected_date_of_return, status) VALUES
('2024-11-07', 201, 101, '2024-11-21', 'Issued'),
('2024-11-07', 202, 102, '2024-11-21', 'Issued'),
('2024-11-07', 203, 103, '2024-11-21', 'Issued');

-- Inserting test data into the book_return table
INSERT INTO book_return (issue_id, actual_date_of_return) VALUES
(1, '2024-11-09'),
(2, '2024-12-04'),
(3, '2024-12-04');

-- 2. Find the details of all books whose title starts with D and are published by PHI.

-- 3. List the book_id and titles of books taken by student "John".

-- 4. Display the count of books issued to each student.
select student_id,count(book_id) as book_count from book_issue where status = 'Issued' group by student_id;

-- 5. Find the book_id and title of books not taken by any students.
select b.book_id,b.title from book b
left join book_issue bi on b.book_id = bi.book_id
where bi.student_id is null;

-- 6. Create a view to display the name of students and title of books issued to them.
create view details as 
select s.name,b.title from book b
join book_issue bi on b.book_id = bi.book_id
join student s on bi.student_id = s.student_id
where bi.status = 'Issued';

-- 7. Implement a procedure to issue a book. The arguments are book_id and student_id. A student can keep an issued book with him/her for a maximum period of two weeks from the date of issue, beyond which a late fee (fine) will be charged. The date of issue attribute must be the same as the system date. The expected date of return attribute should be updated using the DATE_ADD function. If the book is not available to issue, then a proper error message must be displayed. [Hint: use CURDATE() and DATE_ADD function]
delimiter //
create procedure issuing(in bid int, in sid int)
begin
    declare issue_date date;
    declare return_date date;
    declare avail int;
    set issue_date = curdate();
    set return_date = date_add(issue_date,interval 14 day);
    select count(*) into avail from book_issue where book_id = bid and status = 'Issued'; -- checks if the book is in the issued list
    if avail = 0 then -- it means the book is not in the issued list (ie, it is okay to insert)
        insert into book_issue(date_of_issue, book_id, student_id, expected_date_of_return, status) values
        (issue_date,bid,sid,return_date,'Issued');
    else 
        select 'Book not issued' as message;
    end if;
end//
delimiter ;


-- 8. Implement a trigger to update the late fee (fine) in the book_return table. Fine is calculated based on the delay in days of return. The rules for late fee are:
--    - For 0-7 days: Rs 10
--    - For 8-30 days: Rs 100
--    - For days above 30 days: Rs 10 per day
--    [Hint: use DATEDIFF function]

--    book_return:
--    - issue_id is PK and FK referring to book_issue
--    - actual_date_of_return
--    - latedays (number of late days)
--    - latefee (calculated fee)
delimiter //
create trigger return_update
before update on book_return
for each row begin
declare days int;
declare return_date date;
declare return_expected date;
declare fee int;

set return_date = new.actual_date_of_return;
select expected_date_of_return into return_expected from book_issue where issue_id = new.issue_id;
set days = datediff(return_date,return_expected);

if days between 0 and 7 then
    set fee = 10;
elseif days between 8 and 30 then
    set fee = 100;
else 
    set fee = days * 10;
end if;
set new.latedays = days;
set new.latefee = fee;
end//
delimiter ;


-- **Test Data:**
-- book_return:
-- - issue_id 1, actual_date_of_return "2024-11-09", latedays 0, latefee 0
-- - issue_id 2, actual_date_of_return "2024-12-04", latedays 13, latefee 110
-- - issue_id 3, actual_date_of_return "2024-12-04", latedays 13, latefee 110


+---------+-------+----------------+
| book_id | title | publisher_name |
+---------+-------+----------------+
|     201 | DS    | PHI            |
|     202 | CP    | TMH            |
|     203 | DBMS  | Pearson        |
|     204 | DC    | TMH            |
+---------+-------+----------------+
4 rows in set (0.01 sec)

+------------+------+
| student_id | name |
+------------+------+
|        101 | Hari |
|        102 | John |
|        103 | Ali  |
+------------+------+
3 rows in set (0.03 sec)

+----------+---------------+---------+------------+-------------------------+--------+
| issue_id | date_of_issue | book_id | student_id | expected_date_of_return | status |
+----------+---------------+---------+------------+-------------------------+--------+
|        1 | 2024-11-07    |     201 |        101 | 2024-11-21              | Issued |
|        2 | 2024-11-07    |     202 |        102 | 2024-11-21              | Issued |
|        3 | 2024-11-07    |     203 |        103 | 2024-11-21              | Issued |
+----------+---------------+---------+------------+-------------------------+--------+
3 rows in set (0.04 sec)

+----------+-----------------------+----------+---------+
| issue_id | actual_date_of_return | latedays | latefee |
+----------+-----------------------+----------+---------+
|        1 | 2024-11-09            |     NULL |    NULL |
|        2 | 2024-12-04            |     NULL |    NULL |
|        3 | 2024-12-04            |     NULL |    NULL |
+----------+-----------------------+----------+---------+
3 rows in set (0.06 sec)