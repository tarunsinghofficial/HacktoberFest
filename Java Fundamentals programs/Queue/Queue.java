package Queue;
public interface Queue {
    public void enqueue(Object obj);
    public Object dequeue();
    public Object first();
    public int size();
    public boolean isEmpty();
}
