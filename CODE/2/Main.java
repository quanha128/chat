import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in1 = new Scanner(System.in);
        Scanner in2 = new Scanner(System.in);
        int N = in1.nextInt();
        String str = in2.nextLine();
        if (str.charAt(N-1) == 'o') System.out.println("Yes");
        else System.out.println("No");
        in1.close();
        in2.close();
    }
}