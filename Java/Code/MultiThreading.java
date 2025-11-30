import java.util.Random;
class Oddthread extends Thread {
    int num;
    Oddthread(int num) {
        this.num = num;
        start();
    }
    public void run() {
        System.out.println("Cube of " + num + " = " + num * num * num);
    }
}
class Eventhread extends Thread {
    int num;
    Eventhread(int num) {
        this.num = num;
        start();
    }
    public void run() {
        System.out.println("Square of " + num + " = " + num * num);
    }
}
class RandomNumber extends Thread {
    RandomNumber() {
        start();
    }
    public void run() {
        Random r = new Random();
        try {
            for (int i = 0; i < 10; i++) {
                int num = r.nextInt(100);
                Thread.sleep(1000);
                if (num % 2 == 0) {
                    new Eventhread(num);
                } else {
                    new Oddthread(num);
                }
            }
        } catch (Exception e) {
        }
    }
}
class MultiThreading {
    public static void main(String[] args) {
        RandomNumber r = new RandomNumber();
    }
}