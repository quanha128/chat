package L5.exercise4;

import java.util.List;

public class Music extends Media implements Playable{
    private List<String> sounds;
    public Music (String content, List<String> sounds) {
        this.content = content;
        this.sounds = sounds;
    }

    public String play() {
        String result = "";
        for (int i=0; i<sounds.size(); i++) {
            result += sounds.get(i);
        }
        return result;
    }
}
