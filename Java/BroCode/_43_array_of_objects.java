public class _43_array_of_objects {
    public static void main(String[] args) {

        
        _43_car car1 = new _43_car("Ford", "Black");
        _43_car car2 = new _43_car("Corvette", "Blue");
        _43_car car3 = new _43_car("Charger", "Yellow");

        // _43_car[] cars = new _43_car[3];
        // cars[0] = car1;
        // cars[1] = car2;
        // cars[2] = car3;

        // or you can directly do
        _43_car[] cars = {car1, car2, car3};

        // or you could directly do (without intantiating objects seperately) 
        // [these are lnown as ANONYMOUS OBJECTS]
        // _43_car[] cars = {new _43_car("Ford", "Black"),
        //                   new _43_car("Corvette", "Blue"),
        //                   new _43_car("Charger", "Yellow")
        // };

        // -----------------------------------------------------------------

        // for(int i=0;i<cars.length;i++) {
        //     cars[i].details();
        // }

        // using enhanced for-loops
        for(_43_car car: cars) {
            car.details();
        }

        
    }
}
