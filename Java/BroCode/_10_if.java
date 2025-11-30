public class _10_if {
    public static void main(String[] args) {
        int age = 17;

        if(age>=18) {
            System.out.println("You are an adult!");
        }
        else if(age==17) {
            System.out.println("You are almost an adult.");
        }
        else {
            System.out.println("You are a minor...><");
        }

        // ------------------------------------------------
        String name = "";
        if(name.isEmpty()) {
            System.out.println("Name is empty");
        }
        else System.out.println(name);
        // ------------------------------------------------
        Boolean isStudent = true;
        if(isStudent) {
            System.out.println("You are a studnet.");
        }
        else  {
            System.out.println("You are not a student.");
        }
    }
}


