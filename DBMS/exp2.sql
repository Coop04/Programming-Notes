-- mysql> select * from student;
-- +-----------+-------------+-------+---------+-----------+--------------+------------+-----------+

-- | studentNo | studentName | maths | physics | chemistry | cProgramming | department | address   |

-- +-----------+-------------+-------+---------+-----------+--------------+------------+-----------+

-- |       100 | Hari        |    50 |      60 |        45 |           75 | CSE        | Kasaragod |

-- |       101 | Devi        |    60 |      55 |        78 |           40 | CSE        | Kasaragod |

-- |       102 | Sam         |    45 |      77 |        88 |           45 | IT         | Kannur    |

-- |       103 | SreeHari    |    90 |      75 |        77 |           60 | IT         | Calicut   |

-- |       104 | Rani        |    91 |      98 |        89 |           52 | ECE        | Kannur    |

-- |       105 | Raj         |    88 |      77 |        67 |           48 | CSE        | Palakkad  |

-- +-----------+-------------+-------+---------+-----------+--------------+------------+-----------+

-- Create Student table for the following fields:
-- (studentNo, studentName, maths, physics, chemistry, cProgramming, department, address)
CREATE TABLE Student (
    studentNo INT PRIMARY KEY,
    studentName VARCHAR(50),
    maths INT,
    physics INT,
    chemistry INT,
    cProgramming INT,
    department VARCHAR(50),
    address VARCHAR(100));
INSERT INTO Student (studentNo, studentName, maths, physics, chemistry, cProgramming, department, address) VALUES
(100, 'Hari', 50, 60, 45, 75, 'CSE', 'Kasaragod'),
(101, 'Devi', 60, 55, 78, 40, 'CSE', 'Kasaragod'),
(102, 'Sam', 45, 77, 88, 45, 'IT', 'Kannur'),
(103, 'SreeHari', 90, 75, 77, 60, 'IT', 'Calicut'),
(104, 'Rani', 91, 98, 89, 52, 'ECE', 'Kannur'),
(105, 'Raj', 88, 77, 67, 48, 'CSE', 'Palakkad');

-- List the studentno and studentname who is having marks less than 50 in C-programming in ascending order of their marks.
SELECT studentNo, studentName 
FROM Student 
WHERE cProgramming < 50 
ORDER BY cProgramming ASC;

-- List the studentno, studentname and department, in descending order of their department and ascending order of their name.
SELECT studentNo, studentName, department 
FROM Student 
ORDER BY department DESC, studentName ASC;

-- List the name of students whose name starts with ‘S’.
SELECT studentName 
FROM Student 
WHERE studentName LIKE 'S%';

-- Find the name of student who obtained second largest mark in in C-programming.
SELECT studentName 
FROM Student 
ORDER BY cProgramming DESC 
LIMIT 1 OFFSET 1; --LIMIT: no. of items, OFFSET: index

-- List the number of students in each department along with their average mark in maths.
SELECT department, COUNT(*) AS numOfStudents, AVG(maths) AS avgMaths 
FROM Student 
GROUP BY department;

-- List the number of students who have secured marks between 70 and 80 in physics.
SELECT COUNT(*) AS numOfStudents 
FROM Student 
WHERE physics BETWEEN 70 AND 80;