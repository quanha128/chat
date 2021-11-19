package L2;

public class Circle {
    double radius;
    String color;
    int pointX;
    int pointY;

    public Circle(int X, int Y) {
        this.pointX = X;
        this.pointY = Y;
    }

    public Circle(double radius, String color, int X, int Y) {
        this.radius = radius;
        this.color = color;
        this.pointX = X;
        this.pointY = Y;
    }

    public double getArea() {
        return Math.PI * radius * radius;
    }

    public double getCircumference() {
        return Math.PI * 2 * radius;
    }

    public double getDistance(Circle c1) {
        double x = Math.pow(pointX - c1.pointX,2);
        double y = Math.pow(pointY - c1.pointY,2);
        return Math.sqrt(x + y);
    }
}
