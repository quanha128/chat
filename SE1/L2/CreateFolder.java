package L2;

import java.io.FileWriter;
import java.io.IOException;
import java.io.File;

public class CreateFolder {
    public static void main(String[] args) {
        File newfolder = new File("./Practice2-1");
        if (newfolder.mkdir()) {
            System.out.println("Succeeded");
        } else {
            throw new Error("Failed");
        }
        File file = new File("./Practice2-1/sample.txt");
        try {
            FileWriter writer = new FileWriter(file, true);
            writer.write("Hello INIAD");
            writer.close();
        } catch(IOException e) {
            System.out.println("An error occurs.");
        }
    }
}