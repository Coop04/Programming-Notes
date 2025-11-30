-- Create view for following.

-- i.View (student_info) for student table(exp no:2) containing studentNo, studentName, department, address
CREATE VIEW student_info AS
SELECT studentNo, studentName, department, address
FROM Student;

-- ii.View (student_mark) for student table(exp no:2) containing studentNo, studentName, maths, physics,  chemistry, cProgramming.
CREATE VIEW student_mark AS
SELECT studentNo, studentName, maths, physics, chemistry, cProgramming
FROM Student;

-- iii.Display the studentNo, studentName, totalMarks, address from student_info view and student_mark view without referring student table. 
SELECT 
    si.studentNo, 
    si.studentName, 
    (sm.maths + sm.physics + sm.chemistry + sm.cProgramming) AS totalMarks, 
    si.address
FROM 
    student_info si
JOIN 
    student_mark sm ON si.studentNo = sm.studentNo;

-- iv.Create a view (emp_dept) for exp no:3 containing employee name and department name. (NULL values are expected in the department name field for the employees having invalid department numbers).
CREATE VIEW emp_dept AS
SELECT 
    e.empName, 
    d.deptName
FROM 
    emp e
LEFT JOIN 
    dept d ON e.deptNo = d.deptNo; 

-- v.Find the name of employees having invalid department numbers by referring the emp_dept view.  
SELECT empName
FROM emp_dept
WHERE deptName IS NULL;
