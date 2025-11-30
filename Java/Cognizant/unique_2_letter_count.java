/*
A treasure chest has a lock and can be opened only with 2-letter words.
You are given a string S of distinct lowercase English letters.
You can choose any 2 letters from the string and arrange them in any order
to form a 2-letter word.

Your task is to count and return the total number of unique 2-letter words
that can be formed from the string S according to the guidelines above.
If S has fewer than two characters, return 0.

Note: All characters in S are unique.

Input Specification:
input1: A string S of lowercase English letters.

Output Specification:
Return an integer representing the count of unique 2-letter words
that can be formed from the given string.

Example:
Input: abc
Output: 6
*/

public class unique_2_letter_count {
    public static void main(String[] args) {
        int count = 0; 
        String s = "abcde";

        for(int i = 0;i<s.length()-1;i++) {
            for(int j = i+1;j<s.length();j++) {
                count++;
            } 
        }
        count *= 2;
        // or you can directly use the logic of np2 (arrangements) = n*(n-1) (no need for loops)
        System.out.println(count);
    }
}
