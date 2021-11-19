package L2;

import java.util.Scanner;

public class InputSample {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        StringBuffer sb = new StringBuffer();
        while (true) {
            String str = scanner.nextLine();
            if (str.isBlank()) break;
            sb.append(str+"\n");
        };
        String res = sb.toString();
        System.out.printf("%s", res);
        scanner.close();
    }
}