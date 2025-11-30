class Display {
    public void print(int num) {
        System.out.println("Number is : "+num);
    }
}
class Even extends Thread {
    Display d;
    int num;
    Even(Display d,int num) {
        this.d=d;
        this.num=num;
        start();
    }
    public void run() {
        d.print(num);
    }
}
class Odd extends Thread {
    Display d;
    int num;
    Odd(Display d,int num) {
        this.d=d;
        this.num=num;
        start();
    }
    public void run() {
        d.print(num);
    }
}
class Test {
    public static void main(String args[]) {
        Display d=new Display();
        for(int i=0;i<10;i++) {
            try {
            
            if(i%2==0) { 
                new Even(d,i);
                Thread.sleep(1000);
            }}
            catch (Exception e) {
                System.out.println(e.getMessage());
            }} 
            for(int i=0;i<10;i++) {
            try {
            if(i%2!=0){
                new Odd(d,i);
                Thread.sleep(3000);
                
            }}catch (Exception e) {
                System.out.println(e.getMessage());
            }
            
            }
        }
    }
