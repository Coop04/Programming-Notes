public class _41_constructor {
    public static void main(String[] args) {
        _41_student s1 = new _41_student("Spongbob", 30, 3.2);
        _41_student s2 = new _41_student("Cooper", 22, 8.5);

        System.out.println(s1.name);
        System.out.println(s1.age);
        System.out.println(s1.gpa);
        System.out.println(s1.isEnrolled);
        s1.study();

        System.out.println(s2.name);
        System.out.println(s2.age);
        System.out.println(s2.gpa);
        System.out.println(s2.isEnrolled);
        s2.study();
    }
}
