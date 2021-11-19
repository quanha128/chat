package L5.figure;

public class Trapezoid {
    protected final int height;
    protected final int upper;
    protected final int lower;

    public Trapezoid(int height, int upper, int lower) {
        this.height = height;
        this.lower = lower;
        this.upper = upper;
    }

    public int getArea() {
        return (upper + lower)*height/2;
    }
}
