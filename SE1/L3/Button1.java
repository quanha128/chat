package L3;

public class Button1 {
    public String label;
    private boolean pressed;
    private static int numPressed;
    

    public Button1(String str) {
        pressed = false;
        label = str;
    }

    public Button1() {
        label = "Untitled";
        pressed = false;
    }

    public void press() {
        pressed = true;
        numPressed++;
    }

    public void release() {
        pressed = false;
    }

    public boolean isPressed() {
        return pressed;
    }

    public static int getNumPressed() {
        return Button1.numPressed;
    }
}