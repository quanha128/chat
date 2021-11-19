package L6.exercise1;

public class MyStack<E> {
    final private int size;
    private int top;
    private E[] elements;

    @SuppressWarnings("unchecked")
    public MyStack(int size) {
        this.size = size;
        this.top = 0;
        this.elements = (E[]) new Object[size];
    }

    void push(E element) {
        if (top == 0)
            this.elements[top] = element;
        else {
            this.top ++;
            this.top %= size;
            this.elements[top] = element;
        }
    }

    E pop() {
        E popped = this.elements[top];
        this.elements[top] = null;
        top --;
        top %= size;
        return popped;
    }
}
