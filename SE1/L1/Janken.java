package L1;
import java.util.Scanner;
import java.util.Random;

public class Janken {
    public static void main(String[] args) {
        Random r = new Random();
        int cpu = r.nextInt(3);
        System.out.println("あなたの手？0:グー, 1:チョキ, 2:パー");
        Scanner inp = new Scanner(System.in);
        int player = Integer.valueOf(inp.nextLine());
        System.out.println("あなた：" + player);
        System.out.println("コンピューター：" + cpu);
        switch(cpu) {
            case 0:
                if (player==1) System.out.println("コンピューターの勝");
                else if (player==2) System.out.println("あなたの勝");
                else System.out.println("引き分け");
                break;
            case 1:
                if (player==2) System.out.println("コンピューターの勝");
                else if (player==0) System.out.println("あなたの勝");
                else System.out.println("引き分け");
                break;
            case 2:
                if (player==0) System.out.println("コンピューターの勝");
                else if (player==1) System.out.println("あなたの勝");
                else System.out.println("引き分け");
                break;
        }
        inp.close();
    }
}