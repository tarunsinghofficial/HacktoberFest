import java.util.*;
public class _9 {
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
            System.out.print(head.data+" ");
            head=head.next;
        }
        System.out.println();
    }
    static node InsertEnd(node head, int x)
    {   
        node temp=new node(x);
    //    if(head==null)
    //    return temp;
    //    node curr =head;
    //    while(curr.next !=null)
    //    curr=curr.next;
    //    curr.next=temp;
    //     return head;
    if(head==null)
    return temp;
    temp.next=head;
    return temp;

    }
    public static void main(String[] args) {
        // node head=new node(10);
        // head.next=new node(20);
        // head.next.next=new node(30);
        // printList(head);
        // System.out.println("If you want to enter element at last, press 1");
        // Scanner sc=new Scanner(System.in);
        // int t=sc.nextInt();
        // if(t==1)
        // {
        //     int x=sc.nextInt();
        //     node curr=new node(x);
        //     node temp=head;
        //     while(temp.next!=null)
        //     temp=temp.next;
        //     temp.next=curr;
        //     printList(head);
        // }

        node head=null;
        head=InsertEnd(head,10);
        head=InsertEnd(head,20);
        head=InsertEnd(head,30);
        printList(head);

    }
}
