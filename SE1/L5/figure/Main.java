package L5.figure;

public class Main {
    public static void main(String[] args) {
        Trapezoid trapezoid = new Trapezoid(10, 7, 6);
        Parallelogram parallelogram = new Parallelogram(7, 10);
        Rhombus rhombus = new Rhombus(7, 10);
        Rectangle rectangle = new Rectangle(7, 10);
        Square square = new Square(7);

        System.out.printf("Area of trapezoid is %d\n", trapezoid.getArea());
        System.out.printf("Area of parallelogram is %d\n", parallelogram.getArea());
        System.out.printf("Area of rhombus is %d\n", rhombus.getArea());
        System.out.printf("Area of rectangle is %d\n", rectangle.getArea());
        System.out.printf("Area of square is %d\n", square.getArea());
    }
}
