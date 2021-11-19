package L5.exercise4;

import java.util.List;

public class Movie extends Media implements Playable{
    private List<String> sounds;
    private List<String> images;
    public Movie(String content, List<String> sounds, List<String> images) {
        this.content = content;
        this.sounds = sounds;
        this.images = images;
    }

    public String play() {
        String result = "";
        for (int i=0; i<sounds.size(); i++) {
            result += sounds.get(i) + images.get(i);
        }
        return result;
    }
}
