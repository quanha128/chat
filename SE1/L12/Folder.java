import java.util.ArrayList;

public class Folder extends Entry {
  private String name;
  private ArrayList<Entry> children = new ArrayList<Entry>();

  public Folder(String name) {
      this.name =  name;
  }

  public void add(Entry e) {
      this.children.add(e);
  }

  public String getName() {
      return this.name;
  }

  public int getSize() {
    int size = 0;
    for(Entry e: children){
        size += e.getSize();
    }
    return size;
  }
}