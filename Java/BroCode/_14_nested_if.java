public class _14_nested_if {
    public static void main(String[] args) {
        
        boolean isStudent = true;
        boolean isSenior = true;
        double price = 100;

        if(isStudent) {
            if(isSenior) {
                System.out.println("You get a combined discount of 30%");
                price *= .7;
            }
            else {
                System.out.println("You get a student discount of 10%");
                price *= .9;
            }
        }
        else if(isSenior) {
            System.out.println("You get a senior discount of 20%");
            price *= .8;
        }
        else {
            System.out.println("You have no discount");
        }
        System.out.printf("Price of a ticket is $%.2f",price);
    }
}
