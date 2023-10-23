public class _19 {
    static class node{
        int data;
        node next;
        node prev;
        node(int x)
        {
            data=x;
        }
    }
    static void printList(node head)
    {
        while(head!=null)
        {
            System.out.print(head.data);
            head=head.next;
        }
        System.out.println();
    }
    static node Reverse(node head){
        node temp=null;
        if(head==null || head.next==null)
        return head;
        while(head!=null)
        {
                temp=head.prev;
                head.prev=head.next;
                head.next=temp;
                head=head.prev;
        }
        return temp.prev;
    }
    public static void main(String[] args) {
        node head=new node(10);
        node temp1=new node(20);
        node temp2=new node(30);
        node temp3=new node(40);
        head.next=temp1;
        temp1.prev=head;
        temp1.next=temp2;
        temp2.prev=temp1;
        temp2.next=temp3;
        temp3.prev=temp2;
        printList(head);
        head=Reverse(head);
        printList(head);
    }
}
