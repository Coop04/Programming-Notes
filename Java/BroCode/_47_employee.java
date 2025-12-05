public class _47_employee extends _47_person {
    int salary;

    _47_employee(String first, String last, int salary) {
        super(first, last);
        this.salary = salary;
    }

    void show_salary() {
        System.out.println(this.first+"'s salary is "+this.salary);
    }
}
