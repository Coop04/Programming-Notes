import java.io.*;
public class FileCpy {
    public static void main(String[] args) throws IOException {
        FileInputStream f1 = null;
        FileOutputStream f2 = null;
        try {
            f1 = new FileInputStream("D:\\sample.txt");
            f2 = new FileOutputStream("cpy.txt");
            int c;
            do {
                c = f1.read();
                if (c != -1) {
                    f2.write((char) c);
                    System.out.print((char) c);
                }
            } while (c != -1);
        } catch (FileNotFoundException e) {
            System.out.println("File not found exception");
            return;
        } 
    }
}
