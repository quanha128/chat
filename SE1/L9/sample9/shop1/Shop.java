package L9.sample9.shop1;

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

    public Item buy(User customer, String name) {
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
        
        items.remove(matched);
        System.out.printf("%s bought %s.\n", customer.getName(), matched.getName());
        return matched;
    }
}