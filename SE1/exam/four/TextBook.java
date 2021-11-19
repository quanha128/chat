package exam.four;

public final class TextBook extends Book{
    private String subject;

    public TextBook(String title, String subject, int price) {
        super(title, price);
        this.subject = subject;
    }

    public String getTitle() {
        return String.format("%s: %s", subject, title);
    }
}
