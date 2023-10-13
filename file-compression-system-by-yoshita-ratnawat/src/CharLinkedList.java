public class CharLinkedList {
    private CharNode head=null, tail = null;
    private int size=0;

    public boolean isEmpty(){
        return head==null;
    }

    public int size() {
        return size;
    }

    public void add(char ch, String code, int frequency) {
        CharNode newest = new CharNode(ch, code, frequency);
        if(isEmpty()) head = tail = newest;
        else {
            tail.next = newest;
            tail = newest;
        }
        size++;
    }

    public CharNode getCharNode(char ch) {
        if(isEmpty())
            return null;
        CharNode trav = head;
        while(trav != null) {
            if(trav.ch == ch) break;
            trav = trav.next;
        }
        return trav;
    }

    public CharNode getLink() {
        return head;
    }
}
