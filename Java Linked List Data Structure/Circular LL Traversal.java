public class _26 {
    static class node{
        int data;
        node next;
        node(int x)
        {
            data=x;
        }
    }
    static void Traversal(node head)
    {
        if(head==null)
        return;
        node curr=head;
        do{
            System.out.print(head.data+"    ");
            head=head.next;
        }while(head!=curr);
    }
    public static void main(String[] args) {
        node head=new node(10);
        node temp1=new node(20);
        node temp2=new node(30);
        node temp3=new node(40);
        head.next=temp1;
        temp1.next=temp2;
        temp2.next=temp3; 
        temp3.next=head;
        Traversal(head);
    }
}
