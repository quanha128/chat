package L4.assignment1.figures;

import L4.assignment1.base.Figure;

public class Rectangle extends Figure {
    protected final int width;

    public Rectangle(int height, int width) {
        super(height);
        this.width = width;
    }

    @Override
    public void draw() {
        for (int i=0; i<height; i++) {
            String aterisk = "";
            for (int j=0; j<width; j++) {
                aterisk += "*";
            }
            System.out.println(aterisk);
        }
    }
}
