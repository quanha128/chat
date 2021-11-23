package L9.sample9.shop4;

public class ConsoleLogger implements Logger {
    public ConsoleLogger() {
    }

    public void purchase(Customer customer, Item item) {
        System.out.printf("[Purchase] %s: %s(%d yen).\n", customer.getName(), item.getName(), item.getPrice());
    }

    public void balance(User user) {
        System.out.printf("[Balance] %s: %d yen.\n", user.getName(), user.getBalance());
    }

    public void error(User user, String error) {
        System.out.printf("[Error] %s: %s.\n", user.getName(), error);
    }
}