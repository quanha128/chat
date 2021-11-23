package L9.sample9.basic1;

public class Main{
    public static void main(String[] args) {
        User user = new User();
        user.firstName = "Enryo";
        user.familyName = "Inoue";

        System.out.printf("Name : %s %s\n", user.familyName, user.firstName);
    }
}