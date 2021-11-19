package L2;

import java.util.Scanner;

public class MulTable {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = Integer.valueOf(in.nextLine());
        for (int i=1; i<10; i++) {
            System.out.printf("%d x %d = %d\n", n, i, n*i);
        }
        in.close();
    }
}
