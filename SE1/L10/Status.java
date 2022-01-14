package L10;

public class Status {
  private int state;
  private static Status instance = new Status();

  private Status() {
  }

  public int getState() {
    return state;
  }

  public void setState(int state) {
    this.state = state;
  }

  public static Status getInstance() {
    return instance;
  }
}
