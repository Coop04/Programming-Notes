public class _50_abstraction {
    public static void main(String[] args) {
        // abstract = Used to define abstract classes and methods.
        //               Abstraction is the process of hiding implementation details and showing
        //               only the essential features;
        //               Abstract classes CAN'T be instantiated directly 
        //               Can contain 'abstract' methods (which must be implemented)
        //               Can contain 'concrete' methods (which are inherited)

        // _50_shape shape = new _50_shape(); since shape is abstract we can't create any objects from this class

        _50_circle circle = new _50_circle(10);
        _50_triangle triangle = new _50_triangle(10,20);
        _50_rectangle rectangle = new _50_rectangle(10,20);

        circle.display();
        rectangle.display();
        triangle.display();

        System.out.println(circle.area());
        System.out.println(rectangle.area());
        System.out.println(triangle.area());

    }
}
