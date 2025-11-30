public class _40_car {
    String make = "Ford";
    String model = "Mustang";
    int year = 2025;
    double price = 58000.99;
    boolean isRunning = false;

    void start() {
        isRunning = true;
        System.out.println("You start the engine");
        System.out.println("Is car running? "+isRunning);
    }
    void stop() {
        isRunning = false;
        System.out.println("You stop the engine");
        System.out.println("Is car running? "+isRunning);
    }
    void drive() {
        System.out.println("You drive the "+model);
    }
    void brake() {
        System.out.println("You brake the "+model);
    }

}

