package L5.exercise5;

public class TestShoppingClass {
    public static void main(String[] args) {
        ShoppingCart cart = new ShoppingCart();
        cart.addItem(new FreshFood("Beef", 2000));
        cart.addItem(new FreshFood("Salmon", 1000));
        cart.addItem(new Electronics("iPhone", 80000));
        cart.addItem(new Electronics("iPad", 60000));
        cart.removeItem("Salmon");
        System.out.println(cart.getReceipt());
    }
}
