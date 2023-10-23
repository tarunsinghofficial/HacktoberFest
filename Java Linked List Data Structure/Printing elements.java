public class _6{
    static class node{
        int data;
        node next;
        node(int x){
            data=x;
            next=null;
        }
    }
    static void printList(node head)
    {
        while(head!=null)
        {
            System.out.println(head.data);
            head=head.next;
        }
    }
    public static void main(String[] args) {
        node head=new node(10);
        node temp1=new node(20);
        node temp2=new node(30);
        node temp3=new node(40);
        head.next=temp1;
        temp1.next=temp2;
        temp2.next=temp3;
        printList(head);
        printList(temp1);
    }
}