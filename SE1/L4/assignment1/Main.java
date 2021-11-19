package L4.assignment1;

import L4.assignment1.figures.Rectangle;
// import L4.assignment1.base.Figure;
import L4.assignment1.figures.Pyramid;
import L4.assignment1.figures.Square;
import L4.assignment1.figures.WritePyramid;

public class Main {
    public static void main(String[] args) {
        // Figure f = new Figure(4);
        Pyramid p = new Pyramid(4);
        Rectangle r = new Rectangle(4, 6);
        Square s = new Square(10);
        WritePyramid wp = new WritePyramid(10);
        // f.draw();
        System.out.println("---");
        p.draw();
        System.out.println("---");
        r.draw();
        System.out.println("---");
        s.draw();
        wp.write("pyramid10");
    }
}