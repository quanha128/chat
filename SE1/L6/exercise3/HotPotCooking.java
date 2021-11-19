package L6.exercise3;

public class HotPotCooking<T extends Meat, S extends Seasoning> {
    protected T meat;
    protected String[] vegetables = {"Carrot", "Potato", "Onion"};
    protected S seasoning;
    protected String name;

    public HotPotCooking(String name, T meat, S seasoning) {
        this.meat = meat;
        this.seasoning = seasoning;
        this.name = name;
    }

    public void setMeat(T meat) {
        this.meat = meat;
    }

    public void setSeasoning(S seasoning) {
        this.seasoning = seasoning;
    }

    public String getReceipt() {
        return getName() + "\nIngredients: \n" +
               getIngredients() + "\nProcedure: \n" +
               getProcedure() + "\n";
    }

    protected String getName() {
        return this.name;
    }

    protected String getIngredients() {
        String result = "";
        if (this.meat == null || this.seasoning == null) {
            return result;
        }
        for (int i=0; i<vegetables.length; i++) {
            result += "- " + vegetables[i] + "\n";
        }
        result += "- " + this.seasoning.getName() + "\n";
        result += "- " + this.meat.getName() + "\n";
        return result;
    }

    protected String getProcedure() {
        if(this.meat==null || this.seasoning==null) {
            return "";
        }
        return "1. Cut vegetables and a " + this.meat.getName() + "\n" +
               "2. Put vegetables and the meat to a pot and boil them\n" +
               "3. Put " + this.seasoning.getName() + " to the pot";
    }
}
