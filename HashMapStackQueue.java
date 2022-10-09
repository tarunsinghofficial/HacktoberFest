import java.util.*;

public class HashMapStackQueue {
    static class Node{
        int data;
        Node next;
        public Node(int data){
            this.data=data;
            next=null;
        }
    }
    static class Stacks {
        public static Node head;
        public boolean isEmpty(){
            return head==null;
        }

        public void push(int data){
            Node newnode= new Node(data);
            if(isEmpty()){
                head=newnode;
                return;
            }
            newnode.next=head;
            head=newnode;
        }
        public int pop(){
            if(isEmpty())
                return -1;
            int top=head.data;
            head=head.next;
            return top;
        }
        public int peek(){
            if(isEmpty())
                return -1;
            return head.data;
        }
    }
    public static void StackClass(){

        Stack<Integer> s=new Stack<>();
        s.push(1);
        s.push(2);
        while(!s.isEmpty()){
            System.out.println(s.peek());
            s.pop();
        }        
    }

    public static void hashMap(){
        System.out.println("");
        System.out.println("***************HashMap*******************");
        HashMap<String, String> capitalCities = new HashMap<String, String>();

        // Add keys and values (Country, City)
        capitalCities.put("England", "London");
        capitalCities.put("Germany", "Berlin");
        capitalCities.put("Norway", "Oslo");
        capitalCities.put("USA", "Washington DC");
        System.out.println(capitalCities);
        System.out.println(capitalCities.get("England"));
        capitalCities.remove("England");
        System.out.println(capitalCities); 
        System.out.println(capitalCities.size());
        for (String i : capitalCities.keySet()) {
            System.out.println(i);
        }
    }

    public static void QUEUEUE(){
        System.out.println("***************Queue***************");
        Queue<Integer> q=new LinkedList<>();
        q.add(1);
        q.add(2);
        while(!q.isEmpty()){
            System.out.println(q.peek());
            q.remove();
        }         
    }
    public static void main(String args[]) {
        Stacks s=new Stacks();
        s.push(1);
        s.push(2);
        while(!s.isEmpty()){
            System.out.println(s.peek());
            s.pop();
        }

        StackClass();
        hashMap();
        QUEUEUE();
    }
}
