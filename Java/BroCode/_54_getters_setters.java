public class _54_getters_setters {
    public static void main(String[] args) {
        
        _54_car car = new _54_car("Charger", "Yellow", 10000);

        // car.model = "Corvette"; // before model attribute was made private

        // System.out.println(car.color+ " "+car.model+ " "+car.price); // Charger will change to Corvette

        //  we don't want our car to magically change the model
        // so we can add private access modifier when creating that attribute

        // after changing to private (we can't normally acces them outside of the _54_car class
        // line 8 will give error

        // -----------
        // but these values can be accessed through getters and setters

        // They help protect object data and add rules for accessing or modifying
        // GETTER: Methods that make a field READABLE
        // SETTERS: Methods that make a field WRITABLE
        





    }
}
