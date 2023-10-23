import java.util.*;
public class _22 {
    static class node{
        int data;
        node next;
        node(int x)
        {
            data=x;
        }
    }
    static node Insert(node head, int pos, int x)
    {
        node curr=new node(x);
        if(head==null)
        { curr.next=curr;
        return curr;
        }
        int c=0;
        if(head.next==null)
        {
            head.next=curr;
            curr.next=head;
            return head;
        }
        pos-=2; //This was done when doing.........
        node temp=null;
        node copy=head.next,copy1=head;
        while(copy!=copy1)
        {
            c++;
            if(pos==c)
            {
                temp=copy.next;
                copy.next=curr;
                curr.next=temp;
                break;
            }
            copy=copy.next;
        }
        return head;
        
    }
    static void printList(node head)
    {
        System.out.println(head.data+"      ");
        if(head.next==null)
        {
        }
        else{

        node curr=head;
        boolean od=true;
        while(head!=curr || od)
        {
            od=false;
            System.out.print(head.data+"        ");
            head=head.next;
        }
    }
    }
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter number of elements you want to print.");
        int n=sc.nextInt();
        node head=null;
        int m=0;
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                System.out.println("Enter first element");
            int x=sc.nextInt();
            head=Insert(head, 1, x);
            printList(head);
            m++;
            }
            else
            {
                System.out.println();
                System.out.println("Enter element");
                int x=sc.nextInt();
                System.out.println("Enter position");
                int pos=sc.nextInt();
               if(pos>m+1 ||pos<0)
               {
                System.out.println("The position you entered is incorrect.");
                i--;
               }
               else{
                head=Insert(head, pos, x);
                printList(head);
                m++;
               }
               
            }

        }
        // System.out.println();
        // System.out.println(head.data+"   "+head.next.data+"    "+head.next.next.data+"     "+head.next.next.next.data);
    }
}