public class _11 {
    static class node{
        int data;
        node next;
        node(int x)
        {
            data=x;
        }
    }
    static void PrintList(node head)
    {
        while(head!=null)
        {
            System.out.println(head.data);
            head=head.next;
        }
    }
    static node DeleteLast(node head)
    {
        if(head==null)
        System.exit(0);
        node curr=head;
        while(curr.next.next!=null)
        curr=curr.next;
        curr.next=null;
        return head;
    }
    public static void main(String[] args) {
        node head=new node(0);
        head.next=new node(10);
        head.next.next=new node(20);
        head.next.next.next=new node(30);
        PrintList(head);
        head=DeleteLast(head);
        PrintList(head);
    }
}
