import java.util.*;
public class _12 {
    static class node{
        int data;
        node next;
        node(int x)
        {
            data=x;
        }
    }
    static node InsertEnd(node head, int x)
    {
        node curr = new node(x);
        if(head==null)
        {
            head=curr;
            return head;
        }
        node temp=head;
        while(temp.next!=null)
        temp=temp.next;
        temp.next=curr;
        return head;
    }
    static node Insert(node head, int x, int pos)
    {
        node curr=new node(x);
        if(pos==1)
        {
            curr.next=head;
            head=curr;
            return head;
        }
        else
        {
            int c=2;
            node temp=head;
            while(pos!=c)
            {
                c++;
                temp=temp.next;
            }
            node temp1=temp.next;
            temp.next=curr;
            curr.next=temp1;
            return head;
        }
    }
    static void PrintList(node head)
    {
        while(head!=null)
        {
            System.out.print(head.data+" ");
            head=head.next;
        }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        node head=null;
        // System.out.println("how many elements do you need to input?");
        // int n=sc.nextInt();
        // for(int i=0;i<n;i++)
        // {
        //     System.out.println("Enter element");
        //     int x=sc.nextInt();
        //     head=InsertEnd(head, x);
        // }
        // PrintList(head);
        // System.out.println();
        System.out.println("How many elements do you want to insert?");
        int n=sc.nextInt();
        int m=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                System.out.println("Enter your first element");
                 head=new node(sc.nextInt());
                 m++;
            }
            else
            {
            System.out.println();
            System.out.println("\nEnter element");
            int x=sc.nextInt();
            System.out.println("\nEnter position");
            int pos=sc.nextInt();
            if(pos>m+1 || pos==0)
            {
                System.out.println("\nThe position you entered is not correct. Please re-enter.");
                i--;
            }
            else
            {
                head=Insert(head, x, pos);
                m=m+1;
            }
            PrintList(head);
        }
    }
    }
}
