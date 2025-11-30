public class _40_oops {
    public static void main(String[] args) {
        // object = an entity that holds data (attributes)
        //          and can perform actions (methods)
        //          it is a refernce data type

        _40_car car = new _40_car();

        // car.isRunning = true;

        // System.out.println(car); // since object is a reference data type, it will give a memory address
        // System.out.println(car.model);
        // System.out.println(car.make);
        // System.out.println(car.year);
        // System.out.println(car.price);
        // System.out.println(car.isRunning);

        System.out.println(car.isRunning);
        car.start();
        car.stop();
        car.drive();
        car.brake();

        // her every object we create from _40_car will have the same attributes (ie, all of them will be ford mustang ...)
        // it would be grat if we could customise each car objects attributes, to do that we use constructors.
    }
}
