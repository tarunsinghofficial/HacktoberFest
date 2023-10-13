public class SinglyLinkedList<T> {
    private LLNode head = null;
    private LLNode tail = null;
    private int size = 0;

    private static class LLNode <T> {
        LLNode next;
        T data;
      
        LLNode(T data) {
            this.data = data;
            next = null;
        }
    }

    public boolean isEmpty() { return head == null; }
    public int size() { return size; }
    public T getHeadData() { return (T) head.data; }
    public T getTailData() { return (T) tail.data; }

    public void addLast(T data) {
        LLNode newest = new LLNode(data);
        if(isEmpty()) head = tail = newest;
        else {
            tail.next = newest;
            tail = newest;
        }
        size++;
    }

    public T removeLast() {
        if(isEmpty())
            throw new RuntimeException("ERROR: List empty");
        T tail_data = (T) tail.data;
        LLNode tail_prev = head;
        while(tail_prev.next != tail) {
            tail_prev = tail_prev.next;
        }
        tail_prev.next = null;
        tail = tail_prev;
        --size;
        return tail_data;
    }

    public T removeFirst() {
        if (isEmpty())
            throw new RuntimeException("ERROR: List empty");
        T head_data = (T) head.data;
        --size;
        head = head.next;
        return head_data;
    }
}
