public class _48_method_overriding {
    public static void main(String[] args) {
        // Method Overriding: When a subclass provides its own 
        //                    implementation of a method that is already defined.
        //                    Allows for code reusablity and give specific implimentations.

        _48_dog dog = new _48_dog();
        _48_cat cat = new _48_cat();
        _48_fish fish = new _48_fish();

        dog.move();
        cat.move();
        fish.move();

    }
}
