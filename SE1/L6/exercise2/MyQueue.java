package L6.exercise2;

public class MyQueue<E> {
    private int size;
    private int tail;
    private int head;
    private E[] elements;

    @SuppressWarnings("unchecked")
    public MyQueue(int size) {
        this.size = size;
        this.tail = 0;
        this.head = 0;
        this.elements = (E[]) new Object[size];
    }

    public void enqueue(E element) {
        this.elements[tail] = element;
        this.tail++;
        this.tail %= this.size;
    }

    public E dequeue() {
        if (tail == 0 && head == 0) return null;
        E ret = this.elements[this.head];
        this.elements[this.head] = null;
        this.head++;
        this.head %= this.size;
        return ret;
    }
}
