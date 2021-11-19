package L3;

public class Button {
    String label;
    boolean pressed;

    public Button(String str) {
        pressed = false;
        label = str;
    }

    public Button() {
        label = "Untitled";
        pressed = false;
    }

    public void press() {
        pressed = true;
    }

    public void release() {
        pressed = false;
    }
}
