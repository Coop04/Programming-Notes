import java.io.*;
class FileMerge {
    public static void main(String args[]) {
        try {
            FileInputStream fin1 = new FileInputStream("Sample1.txt");
            FileInputStream fin2 = new FileInputStream("Sample2.txt");
            FileOutputStream fout = new FileOutputStream("Merged.txt");
            int i;
            while((i=fin1.read())!=-1) {// reads file character by character
                System.out.println((char)i);
                fout.write(i);
            }
            while((i=fin2.read())!=-1) {
                System.out.println((char)i);
                fout.write(i);
            }
            fin1.close();
            fin2.close();
            fout.close();
        }
        catch(Exception e) {
            System.out.println(e.getMessage());
        }
    }
}