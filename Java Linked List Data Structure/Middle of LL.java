import java.util.*;
public class _33 {
    static class node{
        int data;
        node next;
        node(int x)
        {
            data=x;
        }
    }
   static int middle(node head)
   {
        node slow=head;
        node fast=head;
        if(head==null)
        return -1;
        // else if(head.next==null)
        // return head.next.data;
        else
        {
            while(fast!=null && fast.next!=null)
            {
                if(fast.next.next==null)
                {
                    slow=slow.next;
                    break;
                }
                fast=fast.next.next;
                slow=slow.next;
            }
            return slow.data;
        }
   }
   static node InsertSort(node head, int x)
    {
        node temp=new node(x);
        node curr=head;
        if(head==null)
        return temp;
        // else if(head.next==null)
        // {
        //     if(head.data<=x)
        //     {
        //         head.next=temp;
        //         return curr;
        //     }
        //     else
        //     {
        //         temp.next=head;
        //         return temp;
        //     }
        // }
        else
        {
            do{
                if(head.data>=x)
                {
                    temp.next=head;
                    return temp;
                }
                if(head.next==null && head.data<=x)
                {
                    head.next=temp;
                    return curr;
                }
                if(head.next.data>=x)
                {
                    temp.next=head.next;
                    head.next=temp;
                    return curr;
                }
                
                head=head.next;
            }while(head!=null);
        }
        return curr;
    } 
    static void printList(node head)
    {
        while(head!=null)
        {
            System.out.print(head.data+"    ");
            head=head.next;
        }
    }
    public static void main(String[] args) {
        System.out.println("how many elements you want ot print");
        Scanner sc=new Scanner(System.in);
        node head=null;
        int n=sc.nextInt();
        for(int i=0;i<n;i++)
        {
            System.out.println("\nEnter element");
            int x=sc.nextInt();
            head=InsertSort(head, x);
            printList(head);
        }
        int x=middle(head);
        System.out.println("\nThe middle of linked list is : "+x);
    }
}
