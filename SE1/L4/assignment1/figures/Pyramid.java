package L4.assignment1.figures;

import L4.assignment1.base.Figure;

public class Pyramid extends Figure {
    public Pyramid(int height) {
        super(height);
    }

    @Override
    public void draw() {
        String aterisk = "*";
        StringBuffer space = new StringBuffer("");

        for (int n=0; n<height-1; n++) space.append(" ");
        
        for (int i=0; i<height; i++) {
            System.out.println(space.toString() + aterisk);
            if (space.length() > 0) space.setLength(space.length() - 1);
            aterisk += "**";
        }
    }
}
