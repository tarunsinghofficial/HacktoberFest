import java.util.Stack;
public class ReverseStackUsingHelperStack {
    
        public static void reverse(Stack<Integer> s1, Stack<Integer> h){
    
            if(s1.isEmpty()){
                return;
            }
            int a = s1.peek();
            s1.pop();
    
            reverse(s1,h);
            while (s1.isEmpty()!=true){
                h.push(s1.pop());
            }
            s1.push(a);
            while (h.isEmpty()!=true){
                s1.push(h.pop());
            }
        }
        public static void print(Stack<Integer> s1){
            while (s1.isEmpty()!=true){
                System.out.println(s1.pop());
            }
        }
        public static void main(String[] args) {
    
            Stack<Integer> s1 = new Stack<>();
            s1.push(1);
            s1.push(2);
            s1.push(3);
            s1.push(4);
    
            print(s1);
        }
    
      
}
