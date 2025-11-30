public class _21_logical_oprs {
    public static void main(String[] args) {
        // && = AND
        // || = OR
        // !  = NOT

        double temp = 20;
        boolean isSunny = false;
        String username = "Bro_Code";

        if(temp <= 30 && temp>=0 && isSunny) {
            System.out.println("Weather is Good");
        }
        else {
            System.out.println("Bad Weather");
        }
        // -----------------------------------------
        if(temp >= 30 || temp<=0) {
            System.out.println("Weather is Bad");
        }
        else {
            System.out.println("Weather is Good");
        }
        // -----------------------------------------
        if(temp <= 30 && temp>=0 && !isSunny) { // here !isSunny==false which is a true statement
            System.out.println("It's bad weather & it's not sunny><");
        }
        else {
            System.out.println("It's good weather and it's sunny");
        }
        // -------------------------------------------
        if(username.contains(" ") || username.contains("_")) {
            System.out.println("Username should not contain _ or space");
        }
        
    }
}
