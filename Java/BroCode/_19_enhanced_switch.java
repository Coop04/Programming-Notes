public class _19_enhanced_switch {
    public static void main(String[] args) {
        // Enhanced switch = A replacement to many else if statements (Java14 feature)

        // SWITCH
        String day = "Pizzaday";

        switch(day) {
            case "Monday" -> System.out.println("It's a weekday"); // no need for break;
            case "Tuesday" -> System.out.println("It's a weekday");
            case "Wedday" -> System.out.println("It's a weekday");
            case "Thursday" -> System.out.println("It's a weekday");
            case "Friday" -> System.out.println("It's a weekday");
            case "Saturday" -> System.out.println("It's a weekend");
            case "Sunday" -> System.out.println("It's a weekend");
            default -> System.out.println("Is not a day");
        }
        // ----------------------------------------------------------------------
        // ENHANCED SWITCH
        String day1 = "Wednesday";
        switch (day1) {
            case "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" -> System.out.println("It's a weekday");
            case "Saturday", "Sunday" -> System.out.println("It's the weekend");
            default -> System.out.println("It's not a day");
        }
    }
}
