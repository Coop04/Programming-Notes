import java.util.Scanner;
public class _16_substring {
    public static void main(String[] args) {
        // .substring() = A method used to extract a portion of a string
        // string.substring(start, end)

        // String email = "aswanthsatheesh432@gmail.com";
        // String username = email.substring(0,email.indexOf("@"));
        // String domain = email.substring(email.indexOf("@")+1); //+1 to remove @
        // System.out.println(username);
        // System.out.println(domain);

        // -----------------------------------------------------

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an email: ");
        String mail = scanner.nextLine();

        if(mail.contains("@")) {
            String username = mail.substring(0,mail.indexOf("@"));
            String domain = mail.substring(mail.indexOf("@")+1); //+1 to remove @
            System.out.println("Username: "+username);
            System.out.println("Domain  : "+domain);
        }
        else {
            System.out.println("Not a valid email");
        }

        scanner.close();
    }
}
