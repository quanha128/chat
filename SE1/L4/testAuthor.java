package L4;

public class testAuthor {
    public static void main(String[] args) {
        Author author1 = new Author("alice", "alice@abc.com");
        System.out.println(author1.getName());
        System.out.println(author1.getEmail());
        author1.setEmail("alice@gmail.com");
        System.out.println(author1.getEmail());
        System.out.println(author1.toString());

        Book book1 = new Book("The wind", author1, 64);
        System.out.println(book1.getName());
        System.out.println(book1.getAuthor());
        System.out.println(book1.getPrice());
        book1.setPrice(69);
        System.out.println(book1.getPrice());
    }
}
