import java.io.*;
import java.util.*;
public class FileWrite {
    public static void main(String[] args) throws IOException {
        String str = "";
        Scanner sc = new Scanner(System.in);
        FileWriter fw = new FileWriter("D:\\sample.txt");
        System.out.println("Enter the text");
        do {
            str = sc.nextLine();
            if (!str.equals("stop")) {
                fw.write(str);
                fw.write("\n");
            }
        } while (!str.equals("stop"));
        fw.close();
        try {
            FileReader fr = new FileReader("D:\\sample.txt");
            BufferedReader br = new BufferedReader(fr);
            while ((str = br.readLine()) != null) {
                System.out.println(str);
            }
            fr.close();
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        } catch (IOException e) {
            System.out.println("Invalid");
        }
    }
}
