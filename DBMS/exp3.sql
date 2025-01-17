-- Consider the following tables namely “Department” and “Employees”
-- Their schemas ar e as follows
-- dept (deptNO, deptName, deptLocation)
-- emp (empId, empName , deptNo, salary)
-- Where deptNo is the primary key in dept table and empId is primary key in emp table
-- Where deptNo in Employees is NOT a foreign key.

-- TEST CASES
-- mysql> select * from emp;
-- +-------+---------+--------+--------+

-- | empId | empName | deptNo | salary |

-- +-------+---------+--------+--------+

-- |  2001 | Hari    |   1006 |  30000 |

-- |  2002 | Devi    |   1002 |  40000 |

-- |  2003 | Gupta   |   1003 |  50000 |

-- |  2004 | Ravi    |   1004 |  60000 |

-- |  2005 | Rani    |   1007 |  70000 |

-- |  2006 | John    |   1003 |  40000 |

-- +-------+---------+--------+--------+
-- mysql> select * from dept;
-- +--------+-------------+--------------+

-- | deptNo | deptName             | deptLocation |

-- +--------+-------------+--------------+

-- |   1001 | HR                   | Calicut      |

-- |   1002 | Marketing            | Cochin       |

-- |   1003 | Sales                | Trivandrum   |

-- |   1004 | Testing              | Bangalore    |

-- |   1005 | Development          | Bangalore    |

-- +--------+-------------+--------------+

CREATE TABLE dept (
    deptNo INT PRIMARY KEY,
    deptName VARCHAR(50),
    deptLocation VARCHAR(50)
);
INSERT INTO dept (deptNo, deptName, deptLocation) VALUES
(1001, 'HR', 'Calicut'),
(1002, 'Marketing', 'Cochin'),
(1003, 'Sales', 'Trivandrum'),
(1004, 'Testing', 'Bangalore'),
(1005, 'Development', 'Bangalore');
CREATE TABLE emp (
    empId INT PRIMARY KEY,
    empName VARCHAR(50),
    deptNo INT,
    salary INT
);
INSERT INTO emp (empId, empName, deptNo, salary) VALUES
(2001, 'Hari', 1006, 30000),
(2002, 'Devi', 1002, 40000),
(2003, 'Gupta', 1003, 50000),
(2004, 'Ravi', 1004, 60000),
(2005, 'Rani', 1007, 70000),
(2006, 'John', 1003, 40000);

-- i. Display the employee name along with their department name (no need to display the employees with invalid department details)
SELECT emp.empName, dept.deptName
FROM emp
JOIN dept ON emp.deptNo = dept.deptNo;

-- ii. There are some invalid department numbers (present in employee table but are not existing in department table), display all employees (along employee name employee id and their department number) who are part of such invalid department numbers .
SELECT emp.empId, emp.empName, emp.deptNo
FROM emp
LEFT JOIN dept ON emp.deptNo = dept.deptNo
WHERE dept.deptNo IS NULL;

-- iii. Display all the department numbers available with the department and employee tables avoiding duplicates
SELECT deptNo FROM dept
UNION
SELECT deptNo FROM emp;

-- iv. Display department numbers and name of all the departments where no employee exists.
SELECT dept.deptNo, dept.deptName
FROM dept
LEFT JOIN emp ON dept.deptNo = emp.deptNo
WHERE emp.empId IS NULL;

-- v. Display department number, employee id and employee name of employees working at location Cochin
SELECT emp.deptNo, emp.empId, emp.empName
FROM emp
JOIN dept ON emp.deptNo = dept.deptNo
WHERE dept.deptLocation = 'Cochin';

-- vi. Display the details of those who draw the salary greater than the average salary of employee’s from sales department
SELECT emp.*
FROM emp
WHERE emp.salary > (SELECT AVG(salary) FROM emp JOIN dept ON emp.deptNo = dept.deptNo WHERE dept.deptName = 'Sales');

-- vii. The names of employees whose salary is greater than the salary of all the employees in department 1003
SELECT emp.empName
FROM emp
WHERE emp.salary > (SELECT MAX(salary) FROM emp WHERE deptNo = 1003);

-- viii. Give all employees in the 'Sales' department a 20% raise i n salary.
UPDATE emp
SET salary = salary * 1.20
WHERE deptNo = (SELECT deptNo FROM dept WHERE deptName = 'Sales');
