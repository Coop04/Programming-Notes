public class _46_inheritance {
    public static void main(String[] args) {
        // inheritance = one class inherits the attributes and methods from other class
        //               Child <- Parent (single level inheritance)
        //               Child <- Parent <- GrandParent (milti level inheritance)

        _46_dog dog = new _46_dog();
        _46_cat cat = new _46_cat();

        System.out.println(dog.isAlive); //grandparent attribute
        System.out.println(dog.lives); // child attribute
        System.out.println(cat.isAlive);
        System.out.println(cat.lives);

        dog.eat(); // parent method
        dog.speak(); // child method
        cat.eat(); // parent method
        cat.speak(); // child method

    }
}
