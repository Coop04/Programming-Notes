import java.util.*;

public class ConversionCheatSheet {

    public static void main(String[] args) {

        // -------------------------------------------------
        // 1) String ↔ char[]
        // -------------------------------------------------
        String str = "bark";

        // String → char[]
        char[] charArray = str.toCharArray();

        // char[] → String
        String strFromCharArray = new String(charArray);


        // -------------------------------------------------
        // 2) String ↔ StringBuilder
        // -------------------------------------------------
        // String → StringBuilder
        StringBuilder sb = new StringBuilder(str);

        // StringBuilder → String
        String strFromSB = sb.toString();


        // -------------------------------------------------
        // 3) String ↔ String[]
        //    (splitting into words, then joining back)
        // -------------------------------------------------
        String sentence = "apple orange grape";

        // String → String[]   (split by space)
        String[] words = sentence.split(" "); 

        // String[] → String   (join with space)
        String joined = String.join(" ", words);


        // -------------------------------------------------
        // 4) Any array → String (for printing)
        // -------------------------------------------------
        int[] nums = {1, 2, 3, 4};

        // int[] → String (like "[1, 2, 3, 4]")
        String numsAsString = Arrays.toString(nums);

        // String[] → String (like "[apple, orange, grape]")
        String wordsAsString = Arrays.toString(words);


        // -------------------------------------------------
        // 5) String (of numbers) → int[]
        //    Example: "1 2 3 4" → int[]
        // -------------------------------------------------
        String numbersLine = "10 20 30 40";

        // Split into String[]
        String[] numTokens = numbersLine.split(" ");

        // Convert each token to int
        int[] parsedNumbers = new int[numTokens.length];
        for (int i = 0; i < numTokens.length; i++) {
            parsedNumbers[i] = Integer.parseInt(numTokens[i]);
        }


        // -------------------------------------------------
        // 6) Array ↔ ArrayList (for reference types: String, Integer, etc.)
        // -------------------------------------------------

        // ---- String[] ↔ ArrayList<String> ----
        String[] fruitsArray = {"apple", "banana", "cherry"};

        // String[] → ArrayList<String>
        ArrayList<String> fruitsList = new ArrayList<>(Arrays.asList(fruitsArray));

        // ArrayList<String> → String[]
        String[] fruitsArrayBack = fruitsList.toArray(new String[0]);


        // ---- Integer[] ↔ ArrayList<Integer> ----
        Integer[] intObjArray = {1, 2, 3};

        // Integer[] → ArrayList<Integer>
        ArrayList<Integer> intList = new ArrayList<>(Arrays.asList(intObjArray));

        // ArrayList<Integer> → Integer[]
        Integer[] intObjArrayBack = intList.toArray(new Integer[0]);


        // -------------------------------------------------
        // 7) int[] ↔ ArrayList<Integer> (primitive array)
        // -------------------------------------------------

        int[] primitiveArray = {5, 6, 7};

        // int[] → ArrayList<Integer> (manual loop)
        ArrayList<Integer> listFromIntArray = new ArrayList<>();
        for (int n : primitiveArray) {
            listFromIntArray.add(n); // autoboxing int → Integer
        }

        // ArrayList<Integer> → int[] (using stream)
        int[] intArrayBack = listFromIntArray.stream()
                                             .mapToInt(Integer::intValue)
                                             .toArray();


        // -------------------------------------------------
        // 8) char ↔ String
        // -------------------------------------------------
        char ch = 'A';

        // char → String
        String charToString1 = String.valueOf(ch);
        String charToString2 = Character.toString(ch);

        // String → char (if string has at least 1 character)
        char firstChar = str.charAt(0);


        // -------------------------------------------------
        // 9) List ↔ Array (works for any reference type)
        // -------------------------------------------------
        List<String> nameList = new ArrayList<>();
        nameList.add("Bro");
        nameList.add("Code");

        // List<String> → String[]
        String[] nameArray = nameList.toArray(new String[0]);

        // String[] → List<String>
        List<String> nameListBack = Arrays.asList(nameArray);


        // -------------------------------------------------
        // 10) StringBuilder ↔ char[]
        // -------------------------------------------------

        // StringBuilder → char[]
        char[] fromSB = sb.toString().toCharArray();

        // char[] → StringBuilder
        StringBuilder sbFromCharArray = new StringBuilder(new String(charArray));


        // Just printing some stuff so you can see output if you run it
        System.out.println("Original str: " + str);
        System.out.println("charArray: " + Arrays.toString(charArray));
        System.out.println("strFromCharArray: " + strFromCharArray);
        System.out.println("StringBuilder: " + sb);
        System.out.println("strFromSB: " + strFromSB);
        System.out.println("words: " + Arrays.toString(words));
        System.out.println("joined: " + joined);
        System.out.println("numsAsString: " + numsAsString);
        System.out.println("parsedNumbers: " + Arrays.toString(parsedNumbers));
        System.out.println("fruitsList: " + fruitsList);
        System.out.println("fruitsArrayBack: " + Arrays.toString(fruitsArrayBack));
        System.out.println("listFromIntArray: " + listFromIntArray);
        System.out.println("intArrayBack: " + Arrays.toString(intArrayBack));
        System.out.println("charToString1: " + charToString1);
        System.out.println("firstChar of str: " + firstChar);
    }
}
