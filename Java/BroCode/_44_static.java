public class _44_static {
    public static void main(String[] args) {
        // static = makes a variable or method belong to a class rather than to any specific object. 
        //          Commonly used for utility methods (like Math)or shared resources.
        //          eg. we dont use Math by creating an object for Math class like -- Math math = new Math();
        //          instead we directly use the class name Math.round() or Math.abs() etc.

        _44_friend friend1 = new _44_friend("Kuttu");
        _44_friend friend2 = new _44_friend("Lottu");
        _44_friend friend3 = new _44_friend("Sottu");
        _44_friend friend4 = new _44_friend("Pottu");

        // it will all print the same numOfFriends (here 4 since 4 objects are created)
        // System.out.println(friend1.numOfFriends); 
        // System.out.println(friend2.numOfFriends);
        // System.out.println(friend3.numOfFriends);

        // when accessing a static variable / static method, it's actually best to do so through the class itself
        // rather than any object created from it
        System.out.println(_44_friend.numOfFriends); // 3

        _44_friend.showFriends();
    }
}
