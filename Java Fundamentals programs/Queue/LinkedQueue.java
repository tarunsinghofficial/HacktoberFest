
package Queue;

public class LinkedQueue implements Queue {
   
    Node head  = new Node();
    private int size;
    
    private class Node{
        Node next;
        Node prev;
        Object data;
        public Node(){
            next=this;
            prev=this;
        }
        public Node(Node n, Node p, Object d){
            next=n;
            prev=p;
            data=d;
        }
    }
    public void enqueue(Object data){
        head.prev.next=new Node(head,head.prev,data);
        head.prev=head.prev.next;
        size++;
    }
    public Object first(){
        if(head.next==null)
            throw new IllegalStateException();
        return head.next.data;
    }
    public Object dequeue(){
        if(head.next==null)
            throw new IllegalStateException();
        Object d=head.next.data;
        head.next=head.next.next;
        head.next.prev=head;
        size--;
        return d;  
    }
    public int size(){
        return size;
    }
    public boolean isEmpty(){
        return (size==0);
    }
    public String toString(){
         String s="";
        Node p=head.next;
        
        while(p!=null && p.data!=null){
            s+=p.data.toString()+" ";
            p=p.next;
        }
        return s;
    }
    public boolean equal(LinkedQueue l){
        Node n=l.head.next;
        Node p=this.head.next;
        int c=0;
        if(this.size!=l.size) 
            return false;
        else{
            while(p!=null && p.data!=null){
               if(p.data.equals(n.data))
                   c++;
               p=p.next;
               n=n.next;
            }
            if(c==size)
                return true;
            else
                return false;
            
        }
    }
    public void concate(LinkedQueue l){
        
        for(Node i=l.head.next; i!=null &&i.data!=null; i=i.next){
            this.enqueue(i.data);
        }
    }
    public void reverse(){
        Object t;
        Node n=head.next;
        Node p=head.prev;
        for (int i=0; i<=size/2 && n!=head; i++){
            t=n.data;
            n.data=p.data;
            p.data=t;
        }
 

	

    }
     
    public static void main(String args[]){
        LinkedQueue lq = new LinkedQueue();
        lq.enqueue("hello");
        lq.enqueue("pardeep");
        lq.enqueue(5);
        lq.enqueue('t');
       /* System.out.println(lq);
        System.out.println(lq.dequeue());
        System.out.println(lq);*/
       LinkedQueue l=new LinkedQueue();
       l.enqueue("hello");
       l.enqueue("pardeep");
       l.enqueue(5);
       l.enqueue('t');
      // System.out.println(lq.equal(l));
    //  lq.concate(l);
    lq.reverse();
      System.out.println(lq);
        
    }
}
