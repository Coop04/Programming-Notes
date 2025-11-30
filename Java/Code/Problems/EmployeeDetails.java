/*Write a Java program which creates a class named 'Employee' having the following 
members: Name, Age, Phone number, Address, Salary. It also has a method named 'print- Salary( )' 
which prints the salary of the Employee. Two classes 'Officer' and 'Manager' inherits the 
'Employee' class. The 'Officer' and 'Manager' classes have data members 'spe- cialization' 
and 'department' respectively. Now, assign name, age, phone number, address and salary to an 
officer and a manager by making an object of both of these classes and print the same.
 (Exercise to understand inheritance)*/

class Employee {
    String name;
    int age;
    String phoneNo;
    String address;
    int salary;
    Employee(String name,int age,String phoneNo,String address,int salary) {
        this.salary=salary;
        this.name=name;
    }
    void print_salary() {
        System.out.println("Salary of "+name+" is "+salary);
    }
}
class Officer extends Employee {
    String specialization;
    Officer(String name,int age,String phoneNo,String address,int salary,String specialization) {
        super(name,age,phoneNo,address,salary);
        this.specialization=specialization;
    }
}
class Manager extends Employee {
    String department;
    Manager(String name,int age,String phoneNo,String address,int salary,String department) {
        super(name,age,phoneNo,address,salary);
        this.department=department;
    }
}
class EmployeeDetails {
    public static void main(String args[]) {
        Officer officer=new Officer("Aswanth",20,"000000","Gokul Nivas",99999999,"Great");
        Manager manager=new Manager("Rock",50,"222222","8th Street",1000000,"2nd Great");
        officer.print_salary();
        manager.print_salary();
    }
}