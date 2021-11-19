package L6.exercise3;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hot pot cooking receipts!\n");
        HotPotCooking curry = new HotPotCooking<Beef, CurryPaste>("Beef curry", new Beef(), new CurryPaste());
        HotPotCooking stew = new HotPotCooking<Chicken, WhiteSauce>("Chicken stew", new Chicken(), new WhiteSauce());
        HotPotCooking nikujaga = new HotPotCooking<Pork, SoySauce>("Nikujaga", new Pork(), new SoySauce());
        System.out.println(curry.getReceipt());
        System.out.println(stew.getReceipt());
        System.out.println(nikujaga.getReceipt());
    }
}
