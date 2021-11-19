package exam;

import java.util.Scanner;

public class QuestionTwo {
    public static void main(String[] args) {
        int sum = 0;
        Scanner scanner = new Scanner(System.in);
        while (true) {
            String str = scanner.next();
            try {
                sum += Integer.parseInt(str);
            } catch (NumberFormatException e) {
                break;
            }
        };
        System.out.println(sum);
        scanner.close();
    }
}
