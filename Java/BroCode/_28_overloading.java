public class _28_overloading {
    public static void main(String[] args) {
        // overloaded methods = methods that share the same name, but different parameters
        //                      (can also use different types for parameters and fn return type)
        //                      signature = name + parameters (a method signature must be unique ie, name can be same)

        // System.out.println(add(1,2));
        // System.out.println(add(1,2,3)); //overloaded method

        String pizza = bakePizza("flat bread");
        System.out.println(pizza);
        String pizza1 = bakePizza("flat bread", "mozzarella");
        System.out.println(pizza1);


    }

    static double add(double a, double b) {
        return a+b;
    }
    static double add(double a, double b, double c) { // overloaded the above method
        return a+b+c;
    }
    static int add(int a, int b, int c) { // overloaded the above method
        return a+b+c;
    }
    static String bakePizza(String bread) {
        return bread + " pizza";
    }
    static String bakePizza(String bread,String cheese) {
        return cheese + " " + bread + " pizza";
    }

}
