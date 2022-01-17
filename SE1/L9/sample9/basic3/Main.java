package L9.sample9.basic3;

import java.time.LocalDate;

public class Main{
    public static void main(String[] args) {
        User user = new User("Enryo", "Inoue", LocalDate.now());

        System.out.printf("Age : %d \n", user.getAge(LocalDate.of(2023,2,1)));
    }
}