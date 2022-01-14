package L10;

public class Main {
  public static void main(String[] args) {
    Status stat = Status.getInstance();
    // stat.setState(1);
    System.out.printf("Status:%d\n", stat.getState());
  }
}