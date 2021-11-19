package L2;

public class TestCircle {
    public static void main(String[] args) {
        Circle c1 = new Circle(5.0, "green", 5, 10);
        Circle c2 = new Circle(3.0, "yellow", -3, 5);
        double c1Area = c1.getArea();
        double c2Circumference = c2.getCircumference();
        double distance = c1.getDistance(c2);
        System.out.println("c1の面積は "+ c1Area);
        System.out.println("c2の円周は "+ c2Circumference);
        System.out.println("c1とc2の距離は "+ distance);
    }
}
