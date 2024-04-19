import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;


public class ReverseQueUsingStack {
    
        public static void reverse(Queue q1){
    
            Stack s1 = new Stack();
    
            while (q1.isEmpty()!=true){
                s1.push(q1.remove());
            }
            while (s1.isEmpty()!=true){
                q1.add(s1.pop());
            }
            while (q1.isEmpty()!=true){
                System.out.println(q1.remove());
            }
        }
        public static void main(String[] args) {
    
            Queue q1 = new LinkedList();
            q1.add(10);
            q1.add(20);
            q1.add(30);
            q1.add(40);
    
            reverse(q1);
        }
       
}
