public class _41_student {
    String name;
    int age;
    double gpa;
    boolean isEnrolled;

    // CONSTRUCTOR : automatically called when an object of the class is instantiated. 
    //               used to pass in attribute values while creating the object.
    _41_student(String name, int age, double gpa) { 
        // this : refers to the object that we are currently constructing / working with
        // imagine if we are working on s1, this.name is like using s1.name (since s1 is the one being worked on)
        this.name = name; // 2nd name is the age parameter in the constructor
        this.age = age;
        this.gpa = gpa;
        this.isEnrolled = true; // we can also assign values to attributes if needed 
                                // (now we don't necessarily need to use it when creating object) and no need to use it in the constructor as well
                                // (but should do it if we need to set it to false)
    }

    // this can also be written as
//     41_student(String n, int a, double g) {  // no need to use same name as attributes
//         this.name = n;
//         this.age = a;
//         this.gpa = g;
//     }

    // after assigning values to attributes using the constructor, we can use them within methods or we can also change them
    void study() {
        System.out.println(this.name+ " is studying");
    }
}
