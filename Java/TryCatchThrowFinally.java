import java.io.*;
public class TryCatchThrowFinally {
    public static void main(String[] args) {
        try {
            riskyMethod();
        } catch (IOException e) {
            System.err.println("IOException occurred: " + e.getMessage());
        } finally {
            System.out.println("Finally block executed.");
        }
    }
    public static void riskyMethod() throws IOException {
        throw new IOException("Something went wrong!");
    }
}