public class _44_friend {
    String name;
    static int numOfFriends; // it's like the class owns it and its objects can use it, rather than objects owning it
                             // static variables get a default value automatically (int → 0), 
                             // so numOfFriends starts at 0 even though we didn't initialize it
 

    _44_friend(String name) {
        this.name = name;
        numOfFriends++;
    }

    static void showFriends() { // since static data is accessed static must be used before fn. name
        System.out.println("You have "+numOfFriends+" friends!"); // normally we use this.numOfFriends
                                                      // but when working with static variables this is not necessary  
    }
}
