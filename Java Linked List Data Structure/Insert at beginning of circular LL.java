import java.util.*;
public class _27
{
    static class node
    {
        int data;
        node next;
        node(int x)
        {
            data=x;
        }
    }
    static node insertBegin(node head, int x)
    {
        node temp=new node(x);
        if(head==null)
        {
            temp.next=temp;
            return temp;
        }
        else
        {
            temp.next=head.next;
            head.next=temp;
            int t=head.data;
            head.data=temp.data;
            temp.data=t;
            return head;
        }
    }
    static void printList(node head)
    {
        if(head.next==head)
        System.out.println(head.data);
        else
        {
        node curr=head;
        while(curr.next!=head)
        {
            System.out.print(curr.data+" ");
            curr=curr.next;
        }
        System.out.println(curr.data);
    }
    }
    public static void main(String [] args)
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of elements you want to enter");
        node head=null;
        int n=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter element");
            int x=sc.nextInt();
            head=insertBegin(head, x);
            printList(head);
            System.out.println();
        }
    }
}