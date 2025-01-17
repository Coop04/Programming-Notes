import java.io.*;
class FileStrRevCpy {
    String rev(String s) {
        String a="";
        for(int i=s.length()-1;i>=0;i--) {
            a+=s.charAt(i);
        }
        return a;
    }
    public static void main(String args[]) {
        int j=1;
        try {
            FileReader fr=new FileReader("sample.txt");
            BufferedReader br=new BufferedReader(fr);
            FileWriter fw=new FileWriter("cpy.txt");
            FileStrRevCpy f =new FileStrRevCpy();
            String s;
            while((s=br.readLine())!=null) {
                String b=f.rev(s);
                fw.write(j+"."+b +"\n");
                j++;
            }
            fr.close();
            fw.close();
        }
        catch(Exception e) {
            System.out.println(e.getMessage());
        }
    }
}