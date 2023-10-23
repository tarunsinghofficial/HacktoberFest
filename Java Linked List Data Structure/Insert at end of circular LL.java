import java.util.*;
public class _28 {
    static class node
    {
        int data;
        node next;
        node (int x)
        {
            data=x;
        }
    }
    static node insertEnd(node head, int x)
    {
        node temp=new node(x);
        if(head==null)
        {temp.next=temp;
        return temp;}
        else
        {
            node curr=head;
            temp.next=head.next;
            head.next=temp;
            int t=head.data;
            head.data=temp.data;
            temp.data=t;
            return temp;
        }
    }
    static void printList(node head)
    {
        node curr=head;
        while(curr.next!=head)
        {
            System.out.print(curr.data+"  ");
            curr=curr.next;
        }
        System.out.println(curr.data);
        
    }
    public static void main(String [] args)
    {
        Scanner sc=new Scanner(System.in);
        node head=null;
        System.out.println("how many elements do you want to enter");
        int n=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            System.out.println("\nEnter element");
            int x=sc.nextInt();
            head=insertEnd(head, x);
            printList(head);
        }
    }
}
