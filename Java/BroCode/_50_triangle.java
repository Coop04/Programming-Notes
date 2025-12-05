public class _50_triangle extends _50_shape{
    
    double height;
    double base;

    _50_triangle(double height, double base) {
        this.height = height;
        this.base = base;
    }

    double area() {
        double a = .5 * this.height * this.base;
        return a;
    }
}
