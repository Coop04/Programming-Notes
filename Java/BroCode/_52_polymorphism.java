public class _52_polymorphism {
    public static void main(String[] args) {
        // Polymorphism = "POLY" = "MANY"
        //                "MORPH" = "SHAPE"
        //                Objects can identify as other objects.
        //                Objects can be treated as objects of a common superclass.

        //                eg: dog can be identified as a dog, animal or an organism 
        //                    (ie, it can identify as more than one thing)

        // Polymorphism can also be achieved by using interfaces
        // (changes the class files to interfaces & instead of extends use implements)

        _52_car car = new _52_car();
        _52_bike bike = new _52_bike();
        _52_boat boat = new _52_boat();

        _52_vehicle[] vehicles = {car, bike, boat}; // these different objects are put into a _52_vheicle because they also identify as a vehicle

        for(_52_vehicle i: vehicles) {
            i.go();
        }

        System.out.println();

        car.go();
        bike.go();
        boat.go();
    }
}
