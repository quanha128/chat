package L4;

public class TestBook {
    public static void main(String[] args) {
        Author author1 = new Author("Alice", "alice@example.com");
        Book book1 = new Book("Dummy", author1, 5000);

        System.out.println(book1.getName());
        System.out.println(book1.getAuthor());
        System.out.println(book1.getPrice());
        
        author1.setEmail("alice2@example.com");
        book1.setPrice(5500);
        System.out.println(book1.getName());
        System.out.println(book1.getAuthor());
        System.out.println(book1.getPrice());
    }
}
