package L10.sample10.observer3;

public class EchoObserver implements Observer {
    public EchoObserver() {
    }

    public void update(InputScanner scanner) {
        String lastLine = scanner.getLastInput();
        System.out.printf("Echo: %s\n", lastLine);
    }
}