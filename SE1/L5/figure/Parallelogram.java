package L5.figure;

public class Parallelogram extends Trapezoid{
    public Parallelogram(int base, int height) {
        super(height, base, base);
    }

    @Override
    public int getArea() {
        return super.upper * super.height;
    }
}
