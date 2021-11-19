package L3;

public class Quiz {
    public static void main(String[] args) {
        System.out.println(appendAll(args));
    }

    public static String appendAll(String[] args) {
        String res = "";
        for (String str: args)
            res += (str+";");
        return res;
    }
}