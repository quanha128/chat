package L9.sample9.shop1;

public class Main{
    public static void main(String[] args) {
        Shop shop = new Shop();
        User tocho = new User("Yamada");
        User coop = new User("Yoshida");
        User taro = new User("Taro");
        User jiro = new User("Jiro");
        
        Item ramen = new Item(tocho, "Ramen", 400);
        Item okayu = new Item(tocho, "Okayu", 400);
        Item pen = new Item(coop, "Pen", 100);
        Item paper = new Item(coop, "Paper", 100);

        shop.register(ramen);
        shop.register(okayu);
        shop.register(pen);
        shop.register(paper);

        shop.buy(taro, "Ramen");
        shop.buy(taro, "Pen");
        shop.buy(jiro, "Okayu");
        shop.buy(jiro, "Paper");
    }
}