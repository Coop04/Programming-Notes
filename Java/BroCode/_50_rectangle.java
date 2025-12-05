public class _50_rectangle extends _50_shape{
    double height;
    double width;

    _50_rectangle(double height, double width) {
        this.height = height;
        this.width = width;
    }

    double area() {
        double a = this.height * this.width;
        return a;
    }
}
