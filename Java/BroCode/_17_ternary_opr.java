public class _17_ternary_opr {
    public static void main(String[] args) {
        // variable = (condition)? ifTrue : ifFalse;

        int score = 70;

        String passOrFail = (score>=60) ? "PASS" : "FAIL";
        System.out.println(passOrFail);

        int num = 3;
        String oddEven = (num%2==0)? "Even" : "Odd";
        System.out.println(oddEven);

        int hours = 13;
        String time = (hours< 12) ? "AM" : "PM";
        System.out.println(time);
    }
}