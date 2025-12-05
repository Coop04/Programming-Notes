public class _50_circle extends _50_shape{

    double radius;

    _50_circle(double radius) {
        this.radius = radius;
    }

    @Override
    double area() {
        double a = Math.PI * this.radius * this.radius;
        return a;
    }
    
}
