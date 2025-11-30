public class _36_2D_array {
    public static void main(String[] args) {
        String[] fruits = {"apple", "orange", "banana"};
        String[] vegitables = {"tomato", "potato", "carrot"};
        String[] meats = {"chicken", "pork", "beef", "fish"};

        String[][] groceries = {fruits, vegitables, meats}; // instead of names inside the arra, we can also place the arrays directly inside the outer array { }
      
        // changing an element
        groceries[0][1] = "grape";

        for(String[] foods: groceries) { // we use String[] because each element of groceries is an array
            for(String food:foods) { // inside foods each element is a String
                System.out.print(food+ " ");
            }
            System.out.println();
        }
    }
}
