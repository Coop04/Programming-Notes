// primitive: simple value stored directly in memory (stack)
// reference: memory address (stack) that points to the (heap)

// 🔴 Primitive  vs  🔵 Reference
// ------------- --- --------------
//   int              string
//   double           array
//   char             object
//   boolean

// 2 steps to creating a variable
// -------------------------------
// 1. declaration
// 2. assignment

public class _2_variables {
    public static void main(String[] args) {
        int age = 21; // cannot use double values (error)
        int year = 2025;
        System.out.println(age);
        System.out.println("The year is " + year); 
        
        double qty = 10.5; // can use int values (eg. 10 will be shown as 10.0)
        System.out.println(qty);

        char grade = 'A';
        System.out.println("My grade is " + grade);

        boolean isStudent = false; // true or false
        System.out.println("Are you a student? " + isStudent);
        if(isStudent) {
            System.out.println("Yes");
        }
        else {
            System.out.println("Imposter");
        }

        String name = "BroCode"; // within double quotes
        String color = "Green";
        System.out.println(name);
        System.out.println("Hello " + name); // string concatination: joining 2 strings

        System.out.println("My choices are " + year +" " + color);
    }
}


// Primitive Type | Size      | Minimum        | Maximum          | Wrapper Type
// -----------------------------------------------------------------------------
// boolean        | —         | —              | —                | Boolean
// char           | 16 bits   | Unicode 0      | Unicode 2^16 − 1 | Character
// byte           | 8 bits    | -128           | +127             | Byte
// short          | 16 bits   | -2^15          | +2^15 − 1        | Short
// int            | 32 bits   | -2^31          | +2^31 − 1        | Integer
// long           | 64 bits   | -2^63          | +2^63 − 1        | Long
// float          | 32 bits   | IEEE754        | IEEE754          | Float
// double         | 64 bits   | IEEE754        | IEEE754          | Double
// void           | —         | —              | —                | Void
