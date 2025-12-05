public class _47_super {
    public static void main(String[] args) {
        // super = Refers to a parent class (subclass <- superclass)
        //         used in constructors and method overriding 
        //         calls the parent constructor to initialize attributes

        _47_person person = new _47_person("Cooper", "Coop");
        _47_student student = new _47_student("Magnus", "Potter", 9.9);
        _47_employee employee = new _47_employee("Govindh", "Kumar", 100000);


        person.show_name();

        student.show_name();
        student.showGPA();

        employee.show_name();
        employee.show_salary();
    }
}
