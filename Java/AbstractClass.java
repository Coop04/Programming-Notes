abstract class A {
   abstract void display();
}
class B extends A {
    void display() {
        System.out.println("Class B methord");
    }
}
class C extends A {
    void display() {
        System.out.println("Class C methord");
    }
}
class AbstractClass {
    public static void main(String args[]) {
        B b=new B();
        C c=new C();
        b.display();
        c.display();
    }
}