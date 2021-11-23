package L9.sample9.shop2;

import java.util.List;
import java.util.ArrayList;

public class Shop {
    private List<Item> items = new ArrayList<Item>();

    public Shop() {
    }

    public void register(Item item) {
        items.add(item);

        System.out.printf("%s sells %s.\n", item.getSeller().getName(), item.getName());
    }

    public Item buy(Customer customer, String name) {
        Item matched = null;
        for(Item item : items) {
            if(item.getName().equals(name)) {
                matched = item;
                break;
            }
        }
        if(matched == null) {
            System.out.printf("%s is not found.\n", name);
            return null;
        }

        Seller seller = matched.getSeller();
        int price = matched.getPrice();
        if(customer.getBalance() < price) {
            System.out.printf("%s has not enough money to buy %s.\n", customer.getName(), name);
            return null;
        }
        
        seller.transfer(price);
        customer.withdraw(price);
        
        items.remove(matched);
        System.out.printf("%s bought %s.\n", customer.getName(), name);
        System.out.printf("%s has %d yen\n", customer.getName(), customer.getBalance());
        System.out.printf("%s has %d yen\n", seller.getName(), seller.getBalance());
        
        return matched;
    }
}