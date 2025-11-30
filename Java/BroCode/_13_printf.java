public class _13_printf {

    // printf() : used to format output
    // %[flag][width][.precision][specifier-character]
    
    public static void main(String[] args) {
        System.out.println(Math.PI);

        // printf() can be use to limit the numbers after decimal
        System.out.printf("%.2f", Math.PI);

        double area = 12333.3443521;
        System.out.printf("\n%.3fcm²", area); // alt + 0178 for ² 

        // ---------------------------------------------------------------
        System.out.println();

        String name = "Spongebob";
        char firstLetter = 'S';
        int age = 30;
        double height = 60.5;
        boolean isEmployed = true;

        // Specifier Characters
        System.out.printf("Hello %s", name);
        System.out.printf("\nFirst character: %c", firstLetter);
        System.out.printf("\nYou are %d years old",age);
        System.out.printf("\nHeight: %fcm",height);
        System.out.printf("\nEmployed: %b",isEmployed);

        System.out.printf("\n%s is %d years old.",name,age);

        // -----------------------------------------------------------------

        // Precision
        System.out.printf("\nHeight: %.2fcm",height);
        System.out.printf("\nHeight: %.3fcm",height);

        // -----------------------------------------------------------------

        // Flags

        // + = output a plus
        // , = comma grouping seperator (in thousands place)
        // ( = negative numbers are enclosed in ()
        // space = display a minus if negative, space if positive

        double price1 = 9000000.99;
        double price2 = 100.15;
        double price3 = -54.01;

        double num = 23.34453;
        System.out.printf("\n%+.2f",num); // +23.34

        System.out.printf("\n%,.2f",price1); // 9,000,000.99
        System.out.printf("\n%,.2f",price2); // no change
        System.out.printf("\n%,.2f",price3); // no change

        System.out.printf("\n%(.2f",price3); // (54.01) ie, only changes apply for -ve values
        System.out.printf("\n%(.2f",price2); // 100.15
        
        System.out.printf("\n% .2f",price1); //  9000000.99  (space : used for alligning characters) 
        System.out.printf("\n% .2f",price2); //  100.15
        System.out.printf("\n% .2f",price3); // -54.01

        // -----------------------------------------------------------------------------

        // Width

        // 0 = zero padding
        // number = right justified padding
        // negative number = left justified padding

        int id1 = 1;
        int id2 = 23;
        int id3 = 456;
        int id4 = 7890;

        // zero padding
        System.out.printf("\n%04d",id1); // 0 means zero padding & 4 means with how many characters are we padding
        System.out.printf("\n%04d",id2);
        System.out.printf("\n%04d",id3);
        System.out.printf("\n%04d",id4);
        
        // right justified
        System.out.printf("\n%4d",id1);
        System.out.printf("\n%4d",id2);
        System.out.printf("\n%4d",id3);
        System.out.printf("\n%4d",id4);

        // left justified
        System.out.printf("\n%-4d",id1); 
        System.out.printf("\n%-4d",id2);
        System.out.printf("\n%-4d",id3);
        System.out.printf("\n%-4d",id4);
    }
}
