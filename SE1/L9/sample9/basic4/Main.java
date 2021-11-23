package L9.sample9.basic4;

public class Main{
    public static void main(String[] args) {
        User user1 = new User("Enryo", "Inoue");
        User user2 = new User("Yukichi", "Fukuzawa");

        System.out.printf("Id : %d \n", user1.getId());
        System.out.printf("Name : %s \n", user1.getName());

        System.out.printf("Id : %d \n", user2.getId());
        System.out.printf("Name : %s \n", user2.getName());
    }
}