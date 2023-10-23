
public class _10 {
    static class node{
        int data;
        node next;
        node(int x)
        {
            data=x;
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
    static node DeleteFirst(node head)
    {
        if(head==null)
        System.exit(0);
        else
        head=head.next;
        return head;

    }
    public static void main(String[] args) {
        node head=new node(0);
        head.next=new node(10);
        head.next.next=new node(20);
        head.next.next.next=new node(30);
        printList(head);
        // head=head.next;
        System.out.println();
        // printList(head);
        head=DeleteFirst(head);
        printList(head);
    }
}
