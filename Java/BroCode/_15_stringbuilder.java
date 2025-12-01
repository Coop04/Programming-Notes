public class _15_stringbuilder {
    public static void main(String[] args) {
        StringBuilder sb = new StringBuilder("Tony"); // sb is a string, its type is StringBuilder
        System.out.println(sb);

        // character at index 0
        System.out.println(sb.charAt(0));

        // set charecter at index
        sb.setCharAt(0,'P');
        System.out.println(sb); // Pony

        // insert
        sb.insert(0, 'S');
        System.out.println(sb); // SPony

        sb.insert(3,'n');
        System.out.println(sb); //SPonny

        // delete
        sb.delete(0, 2); // end index is exclusive
        System.out.println(sb); //onny

        // appending
        StringBuilder s = new StringBuilder("h");
        s.append("e");
        s.append("l");
        s.append("lo");
        System.out.println(s);

        // length
        System.out.println(s.length());

        // reverse
        s.reverse();
        System.out.println(s); // reverses the same sting inplace

        // reverse and store it to another string
        String greet = "hola";
        String sReverse = new StringBuilder(greet).reverse().toString(); // to string converts StringBuilder into a string
        System.out.println(sReverse);
        System.out.println(greet);

        // -----------------------------------------------
        // reversal stringbuilder (without reverse()) inplace
        StringBuilder str = new StringBuilder("hey");
        for(int i=0;i<str.length()/2;i++) {
            int front = i;
            int back = str.length()-1-i;

            char frontChar = str.charAt(front);
            char backChar = str.charAt(back);

            str.setCharAt(front, backChar);
            str.setCharAt(back, frontChar);
        }
        System.out.println(str);

        // reversing string the normal way
        String dog = "bark";
        char[] arr = dog.toCharArray();
        for(int i=0;i<dog.length()/2;i++) {
            int first = i;
            int last = dog.length()-1-i;
            
            char temp = arr[first];
            arr[first] = arr[last];
            arr[last] = temp;
        }
        String rev = new String(arr);
        System.out.println(rev);
    }
}
