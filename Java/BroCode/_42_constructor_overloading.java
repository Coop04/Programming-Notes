public class _42_constructor_overloading {
    public static void main(String[] args) {
        // overloading constructors =  allow a class to have multiple constructors
        //                             with different parameter lists.
        //                             Enable objects to be initialized in various ways.
        //                             (by passing in various number of arguements)
        
        
        _42_user user1 = new _42_user("Cooper");
        _42_user user2 = new _42_user("Coop","cooper123@gmail.com");
        _42_user user3 = new _42_user("Ram","ram@gmail.com", 32);
        _42_user user4 = new _42_user();

        System.out.println(user1.username);
        System.out.println(user1.email);
        System.out.println(user1.age);
        
        System.out.println(user2.username);
        System.out.println(user2.email);
        System.out.println(user2.age);

        System.out.println(user3.username);
        System.out.println(user3.email);
        System.out.println(user3.age);

        System.out.println(user4.username);
        System.out.println(user4.email);
        System.out.println(user4.age);
    }
}
