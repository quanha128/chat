package L2;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;

public class InputSample2 {
    public static void write(String str) {
        try {
            File file = new File("result.txt");
            FileWriter writer = new FileWriter(file, true);
            writer.write(str);
            writer.close();
        } catch(IOException e) {
            System.out.println("An error occurs.");
        }
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuffer sb = new StringBuffer();
        while (true) {
            String str = scanner.nextLine();
            if (str.isBlank()) break;
            sb.append(str+"\n");
        };
        String res = sb.toString();
        System.out.printf("%s",res);
        write(res);
        scanner.close();
    }
}
