public class _51_interface {
    public static void main(String[] args) {
        // Interface = (very similar to an abstract class)
        //             A blueprint for a class that specifies a set of abstract methods that 
        //             implementing class must define. (no need to add 'abstract' keyword to those methods)
        //             Supports multiple inheritance-like behaviour. (noramlly a child can only have one parent, but with interfaces multiple inheritance is possible)
        //             Key difference with abstract classes is that you can implement multiple interfaces

        _51_rabbit rabbit = new _51_rabbit();
        _51_hawk hawk = new _51_hawk();
        _51_fish fish = new _51_fish();

        rabbit.flee();
        hawk.hunt();

        // _51_fish class has implemented both the predator and prey interfaces
        fish.flee();
        fish.hunt();
    }
}
