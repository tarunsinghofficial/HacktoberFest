public class LinkedList {
    public static class Node{
        int data;
        Node next;

        public Node(int data){
            this.data = data;
            this.next = null;
        }
    }

    public static Node head;
    public static Node tail;
    public static int size;

    public void addFirst(int data){
        Node newNode = new Node(data);
        size++;
        if(head == null){
            head = tail = newNode;
            return;
        }

        newNode.next = head;
        head = newNode; 
    }

    public void addLast(int data){
        Node newNode = new Node(data);
        size++;
        if(head == null){
            head = tail = newNode;
            return;
        }

        tail.next = newNode;
        
        tail = newNode;
    }

    public void addMidd(int idx, int data) {
        if(idx == 0){
            addFirst(data);
            return;
        }
        Node newNode = new Node(data);
        size++;
        Node temp = head;
        int i = 0;
        while (i < idx) {
            temp = temp.next;
            i++;
        }

        newNode.next = temp.next;
        temp.next = newNode; 
    }

    public int removeFirst() {
        if(head == null){
            System.out.println("LL is empty");
            return Integer.MIN_VALUE;
        }

        int val = head.data;
        size--;
        if(head == tail){
            head = tail = null;
            return val;
        }
        head = head.next;
        return val;
    }

    public int removeLast() {
        if(head == null){
            System.out.println("LL is empty");
            return Integer.MIN_VALUE;
        }

        int val = head.data;
        size--;
        if(head == tail){
            head = tail = null;
            
            return val;
        }
        Node prev = head;

        while(prev.next!=tail){
            prev = prev.next;
        }
        val = prev.next.data;
        prev.next = tail;
        tail = prev;
        
        return val;
    }

    public void print() {
        Node temp = head;

        while (temp!=null) {
            System.out.print(temp.data + "->");
            temp = temp.next;
        }
        System.out.print("null");
        System.out.println();
    }

    // Searching In linked list

    public int itrSearch(int key) {
        if(head == null){
            return -1;
        }

        int i = 0;
        Node temp = head;

        while(temp!=null){
            if(temp.data == key)
                return i;
            i++;
            temp = temp.next;
        }

        return -1;
    }

    // Searching Using recursion

    // public int recSearch(int key, Node start) {
        
    // }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();

        ll.addFirst(1);
        ll.print();
        ll.addLast(2);
        ll.print();
        ll.addLast(4);
        ll.print();
        ll.addMidd(2, 3);
        ll.print();
    }
}
