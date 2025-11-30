import java.io.*;
class FileStringCopy {
    public static void main(String args[]) {
        try{
            FileReader fr = new FileReader("Sample1.txt");
            BufferedReader br = new BufferedReader(fr);
            FileWriter fw = new FileWriter("StringCopy.txt");
            String s;
            int i=1;
            while((s=br.readLine())!=null) {
                System.out.println(i+"."+s);
                fw.write(i+"."+s+"\n");// when writing close is mandatory
                i=i+1;
            }  
            fr.close();
            fw.close();    
        }
        catch(Exception e) {
            System.out.println(e.getMessage());
        }
    }
}