public class _47_student extends _47_person {
    
    double gpa;

    _47_student(String first, String last, double gpa) {
        super(first, last);
        this.gpa = gpa;
    }

    void showGPA() {
        System.out.println(this.first + "'s gpa is "+this.gpa);
    }
}
