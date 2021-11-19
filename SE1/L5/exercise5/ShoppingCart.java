package L5.exercise5;

import java.util.ArrayList;

public class ShoppingCart {
    private ArrayList<Product> items;
    private double total;
    private double totalWithTax;

    public ShoppingCart() {
        this.items = new ArrayList<Product>();
        this.total = 0;
        this.totalWithTax = 0;
    }

    public void addItem(Product product) {
        this.items.add(product);
        this.total += product.getPrice();
        this.totalWithTax += product.getTaxIncludedPrice();
        System.out.println("+ "+product.getName());
    }

    public void removeItem(String name) {
        for (Product item : this.items)
            if (item.getName() == name){
                this.total -= item.getPrice();
                this.totalWithTax -= item.getTaxIncludedPrice();
                items.remove(item);
                System.out.println("- "+name);
                break;
            }
    }

    public String getReceipt() {
        String line = new String(new char[40]).replace("\0", "-");
        String res = String.format("%s\nSales Receipt\n%s\n", line,line);
        for (int i=0; i<items.size(); i++) {
            res += String.format(
                "%d\t%s\t\t%.1f\n",
                i+1,
                items.get(i).getName(),
                items.get(i).getTaxIncludedPrice()
            );
        }
        res += line+"\n";
        res += String.format(" \tTax\t\t%.1f\n", this.totalWithTax-this.total);
        res += String.format(" \tTotal\t\t%.1f", this.totalWithTax);
        return res;
    }
}
