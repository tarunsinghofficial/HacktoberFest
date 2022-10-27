class Node<T>{
    T data;
    Node<T> next;

    Node(T data){
        this.data = data;
    }
}

public class ReverseLinkedList {
    
        public static Node<Integer> reverse(Node<Integer> head){
    
            if(head.next==null){
                return head;
            }
            Node<Integer> small = reverse(head.next);
            Node<Integer> tail = small;
            while (tail.next!=null){
                tail = tail.next;
            }
            tail.next = head;
            head.next = null;
    
            return small;
        }
    
        public static void print(Node<Integer> head){
    
            Node<Integer> temp = head;
    
            while (temp!=null){
                System.out.println(temp.data);
                temp = temp.next;
            }
        }
        public static void main(String[] args) {
            Node<Integer> n1 = new Node<>(10);
            Node<Integer> n2 = new Node<>(20);
            Node<Integer> n3 = new Node<>(30);
            Node<Integer> n4 = new Node<>(40);
    
            n1.next = n2;
            n2.next = n3;
            n3.next = n4;
            n4.next = null;
    
            Node<Integer> head = reverse(n1);
            print(head);
        }
    }
    
