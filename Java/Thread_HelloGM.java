class Hello extends Thread {
    public void run() {
        for(int i=0;i<3;i++) {
            System.out.println("Hello");
            try {
                Thread.sleep(3000);
            }
            catch(Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
class GoodMorning extends Thread {
    public void run() {
        for(int i=0;i<5;i++) {
            System.out.println("GoodMorning");
            try {
                Thread.sleep(1000);
            }
            catch(Exception e) {
                System.out.println(e.getMessage());
            }
        }
    }
}
class Thread_HelloGM {
    public static void main(String args[]) {
        Hello h=new Hello();
        GoodMorning g=new GoodMorning();

        h.start();
        g.start();
    }
}