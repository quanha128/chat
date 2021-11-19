package L5.exercise4;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        Image image = new Image("☆");
        System.out.println(image.show());

        Music music = new Music("♪Twinkle twinkle little star", Arrays.<String>asList("C","C","G","G","A","A","G"));
        System.out.println("Music shows " + music.show());
        System.out.println("Music shows " + music.play());

        Movie movie = new Movie(
            "Twinkle twinkle little star", 
            Arrays.<String>asList("C","C","G","G","A","A","G"),
            Arrays.<String>asList("☆","☆","★","★","☆","☆","★")
        );
        System.out.println("Movie shows " + movie.show());
        System.out.println("Movie shows " + movie.play());
    }
}
