package L4.assignment1.figures;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import L4.assignment1.base.Writable;

public class WritePyramid extends Pyramid implements Writable{
    public WritePyramid(int height) {
        super(height);
    }

    public String drawP() {
        String res = "";
        String aterisk = "*";
        StringBuffer space = new StringBuffer("");

        for (int n=0; n<height-1; n++) space.append(" ");
        
        for (int i=0; i<height; i++) {
            res += (space.toString() + aterisk + "\n");
            if (space.length() > 0) space.setLength(space.length() - 1);
            aterisk += "**";
        }
        return res;
    }

    @Override
    public void write(String filename) {
        try {
            File f = new File(filename);
            FileWriter writer = new FileWriter(f, true);
            writer.write(drawP());
            writer.close();
        } catch(IOException e) {
            System.out.println("write error");
        }
    }
}
