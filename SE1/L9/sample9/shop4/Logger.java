package L9.sample9.shop4;

public interface Logger {
    public void purchase(Customer customer, Item item);
    public void balance(User user);
    public void error(User user, String error);
}