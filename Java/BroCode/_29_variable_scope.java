public class _29_variable_scope {

    static int y = 3; // CLASS SCOPE
    public static void main(String[] args) {
        int x = 1; // LOCAL SCOPE
        System.out.println(x);
        System.out.println(y); // prints value of y since it has a scope of the whole class

        int y = 10; //LOCAL
        System.out.println(y); // LOCAL SCOPE has higher priority than CLASS scope

        doSomething(); // this method doesn't know about the x above

    }
    static void doSomething() {
        int x = 2; // LOCAL SCOPE
        System.out.println(x);
        System.out.println(y);
    }
}
