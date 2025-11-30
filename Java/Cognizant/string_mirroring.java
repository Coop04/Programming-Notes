public class string_mirroring {
    public static void main(String[] args) {
        String s = "programming";
        char[] chars = s.toCharArray();

        for(int i=0;i<s.length();i++) {
            if((int)(chars[i]) < (int)(mirror(chars[i]))) {
                chars[i] = mirror(chars[i]);
            }
            else {
                continue;
            }
        }
        String mirror = new String(chars); // converting character array to string
        System.out.println(mirror);
    }
    static char mirror(char c) {
        char mirror = (char)('z'-(c-'a'));
        return mirror;
    }
}
