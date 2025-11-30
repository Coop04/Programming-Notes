class Calculator {
    public int add(int a, int b) {
        return a + b;
    }

    public double add(double a, double b) {
        return a + b;
    }
}

public class Main {
    public static void main(String[] args) {
        Calculator calc = new Calculator();
        int sum1 = calc.add(5, 3); // Invokes the first add method
        double sum2 = calc.add(2.5, 3.5); // Invokes the second add method
        
        System.out.println("Sum1: " + sum1); // Output: Sum1: 8
        System.out.println("Sum2: " + sum2); // Output: Sum2: 6.0
    }
}
