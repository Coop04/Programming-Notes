import java.util.HashMap;
public class char_frequency {
    public static void main(String[] args) {
        String s = "cooper";
        char[] chars = s.toCharArray();
        int[] frequency = new int[26];
        HashMap<Character, Integer> map = new HashMap<>();

        for(char ch: chars) {
            frequency[ch-'a']++;
        }

        for(int i = 0;i<26;i++) {
            if(frequency[i]>0) {
                char letter = (char)(i+'a');
                map.put(letter, frequency[i]);
            }
        }
        System.out.println(map);

        System.out.println("Sorted by value desc:");
        map.entrySet()
            .stream()
            .sorted((a,b) -> b.getValue() - a.getValue())
            .forEach(System.out::println);

    }
}
