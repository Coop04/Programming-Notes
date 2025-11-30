public class _12_math {
    public static void main(String[] args) {
        System.out.println(Math.PI);
        System.out.println(Math.E);

        // no need to import Math

        double result = Math.pow(2, 3);
        System.out.println(result);

        double abs = Math.abs(-5);
        System.out.println(abs);

        double sqrt = Math.sqrt(9);
        System.out.println(sqrt);

        double round = Math.round(5.5); // use double as data type of variable
        System.out.println(round);

        double ceil = Math.ceil(55.3); // use double as data type of variable
        System.out.println(ceil);

        double floor = Math.floor(55.3);
        System.out.println(floor);

        double max = Math.max(10,20);
        double min = Math.min(10,20);
        System.out.println(min+ "\t" +max);
    }
}
