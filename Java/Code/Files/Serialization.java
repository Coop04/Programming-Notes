import java.io.*;

class Person implements Serializable {
    private int age;
    private String name;

    public Person(int age,String name) {
        this.age=age;
        this.name=name;
    }

    public void display() {
        System.out.println("Name :"+name+"\nAge :"+age);
    }
}
class Serialization {
    public static void main(String args[]) {
        Person p=new Person(20,"Aswanth");
        /*
        try {
            FileOutputStream fout=new FileOutputStream("Person.dat");
            ObjectOutputStream obj=new ObjectOutputStream(fout);
            obj.writeObject(p);
            fout.close();
        }
        catch(Exception e){
            System.out.println(e.getMessage());
        }
        */
       try {
            FileInputStream fin=new FileInputStream("Person.dat");
            ObjectInputStream obj=new ObjectInputStream(fin);
            Person q=(Person)obj.readObject();
            fin.close();
            q.display();
       }
       catch(Exception e){
            System.out.println(e.getMessage());
        }
    }
}