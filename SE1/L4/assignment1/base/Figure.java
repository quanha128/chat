package L4.assignment1.base;

abstract public class Figure {
    protected final int height;

    public Figure(int height) {this.height = height;}

    abstract public void draw();
}