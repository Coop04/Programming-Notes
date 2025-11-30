public class _15_string_methods {
    public static void main(String[] args) {
        String name = "Bro Code";

        int length = name.length(); // 8
        char letter = name.charAt(4); // C
        int index = name.indexOf("o"); // 2 (can be "o" or 'o')
        int lindex = name.lastIndexOf("o"); // 5

        name = name.toUpperCase(); // BRO CODE
        name = name.toLowerCase(); // bro code

        String name1 = "    Bro Code    ";
        name1 = name1.trim(); // Bro Code

        name1 = name1.replace("o","a"); // Bra Cade

        System.out.println(name1);

        // System.out.println(name1.isEmpty()); // false

        // -------------------------------------------------------
        // checking id string has a character

        if(name.contains(" ")) {
            System.out.println("Your name contains a space");
        }
        else {
            System.out.println("Your name does not contain a space");
        }
        
        //------------------------------------------------------------- 

        // Checking if 2 strings are equal
        if(name.equals("bro code")) {
            System.out.println("Your name is brocode");
        }
        else {
            System.out.println("You are an imposter");
        }
        // -------------------------------------------

        // string to string array
        String s = "a,b,c,d";
        String[] words = s.split(","); // you can split from anywhere with the seperator symbol
        for(String i: words) {
            System.out.print(i+" ");
        }

        System.out.println();

        // string to char array
        String st = "pqrst";
        char[] ch = st.toCharArray();
        for(char i: ch) {
            System.out.print(i+" ");
        }
        
    }
}
