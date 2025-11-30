import java.util.HashMap;

public class _xx_hashmap {
    public static void main(String[] args) {
        // Hashmao = A data structure that stores key-value pairs 
        // Keys are unique, but values can be duplicated
        // Does not maintain any order, but is memory efficient
        // Hashmap<Key, Value>

        HashMap<String, Double> map = new HashMap<>();
        map.put("apple", 0.50);
        map.put("orange", 0.75);
        map.put("banana", 0.25);
        map.put("coconut", 1.00);

        map.put("orange", 100000.0); // when dupilcate key values are added, it will overwrite existing value

        // to remove an element
        map.remove("orange");

        System.out.println(map); 


        // to get a value associated with a key
        System.out.println(map.get("coconut")); // 1.0

        // to check if a key exists
        System.out.println(map.containsKey("banana"));
        if(map.containsKey("coconut")) {
            System.out.println(map.get("coconut"));
        }
        else {
            System.out.println("key not found");
        }

        // to check if a value exists
        System.out.println(map.containsValue(1.0)); // pay attention to the datatype, here double is used (int will not auto convert to double)

        // to get size of the map
        System.out.println(map.size());

        for(String key: map.keySet()){ // keySet() method will return all the keys (it's iterable like array)
            System.out.println(key + ": $"+map.get(key));
        }
    }
}
