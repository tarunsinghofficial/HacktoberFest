class Node<T>{
    T data;
    Node<T> next;

    Node(T data){
        this.data = data;
    }
}
public class MergingTwoCircularLL {


        public static void print(Node<Integer> head){
    
            Node<Integer> temp = head;
    
            do{
                System.out.println(temp.data);
                temp = temp.next;
    
            }while (temp!=head);
    
        }
    
       public static Node<Integer> concat(Node<Integer> head1,Node<Integer> head2){
           Node<Integer> h1 = head1;
           Node<Integer> t1 = head1;
           Node<Integer> h2 = head2;
           Node<Integer> t2 = head2;
    
           while (t1.next!=h1){
               t1 = t1.next;
           }
    
           while (t2.next!=h2){
               t2 = t2.next;
           }
           t1.next = h2;
           t2.next = h1;
    
           return h1;
       }

        public static void main(String[] args) {
            Node<Integer> n1 = new Node<>(10);
            Node<Integer> n2 = new Node<>(20);
            Node<Integer> n3 = new Node<>(30);
            Node<Integer> n4 = new Node<>(40);
    
            n1.next = n2;
            n2.next = n3;
            n3.next = n4;
            n4.next = n1;
    
    
           Node<Integer> m1 = new Node<>(50);
           Node<Integer> m2 = new Node<>(60);
           Node<Integer> m3 = new Node<>(70);
           Node<Integer> m4 = new Node<>(80);
    
           m1.next = m2;
           m2.next = m3;
           m3.next = m4;
           m4.next = m1;
    
           Node<Integer> head = concat(n1,m1);
            print(n1);
    
        }
    }
    

