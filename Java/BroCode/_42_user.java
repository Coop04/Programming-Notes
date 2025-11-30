public class _42_user {
    String username;
    String email;
    int age;

    _42_user(String username) {
        this.username = username;
        this.email = "Not provided";
        this.age = 0;
    }

    // constructor overloading
    _42_user(String username, String email) { // constructor that accepts username and email only
        this.username = username;
        this.email = email;
        this.age = 0;
    }

    _42_user(String username, String email, int age) { // constructor that accepts all 
        this.username = username;
        this.email = email;
        this.age = age;
    }

    _42_user() { // constructor that accepts no arguements (by setting only default values)
        this.username = "Guest";
        this.email = "Not provided";
        this.age = 0;
    }



}
