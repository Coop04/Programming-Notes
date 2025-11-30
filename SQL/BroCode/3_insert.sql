-- Active: 1731173242441@@127.0.0.1@3306@brocode
SELECT * from employees;

-- inserting into table
INSERT INTO employees -- when inserting you must enter values for all columns in the table (else error)
VALUES (1, "Eugene", "Krabs", 25.50, "2023-01-02"),
       (2, "Squidward", "Tentacles", 15.00, "2023-01-03"),
       (3, "Spongbob", "Squarepants", 12.50, "2023-01-04"),
       (4, "Patrick", "Star", 12.50, "2023-01-05"),
       (5, "Sandy", "Cheeks", 17.25, "2023-01-06");

-- inorder to insert only some values to the table
INSERT INTO employees (employee_id, first_name, last_name)
VALUES (6, "Sheldon", "Plankton"); -- other column values of the table will appear as NULL