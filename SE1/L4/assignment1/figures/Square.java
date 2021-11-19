package L4.assignment1.figures;

public class Square extends Rectangle {
    public Square(int edge) {
        super(edge, edge);
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
