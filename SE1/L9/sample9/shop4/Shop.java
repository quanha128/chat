package L9.sample9.shop4;

import java.util.List;
import java.util.ArrayList;

public class Shop {
    private List<Item> items = new ArrayList<Item>();
    private Logger logger;

    public Shop(Logger logger) {
        this.logger = logger;
    }

    public void register(Item item) {
        items.add(item);
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
            logger.error(customer, String.format("%s is not found.", name));
            return null;
        }

        Seller seller = matched.getSeller();
        int price = matched.getPrice();
        if(customer.getBalance() < price) {
            logger.error(customer, String.format("Not enough moeny to buy %s.", name));
            return null;
        }
        
        seller.transfer(price);
        customer.withdraw(price);
        
        items.remove(matched);
        logger.purchase(customer, matched);
        logger.balance(customer);
        logger.balance(seller);
        
        return matched;
    }
}