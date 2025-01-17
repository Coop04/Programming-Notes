class Display {
    public static synchronized void print(String msg) {
        System.out.print("["+msg);
        try {
            Thread.sleep(1000);
        }
        catch(Exception e) {
            System.out.println(e.getMessage());
        }
        System.out.print("]");
    }
}
class SyncEg extends Thread {
    Display d;
    String msg;

    public SyncEg(Display d,String msg) {
        this.d=d;
        this.msg=msg;
    }
    
    public void run() {
        d.print(msg);
    }
}
class Sync {
    public static void main(String args[]) {
        Display dis=new Display();
        SyncEg e1=new SyncEg(dis,"Hello");
        SyncEg e2=new SyncEg(dis,"World");

        e1.start();
        e2.start();
    }
}