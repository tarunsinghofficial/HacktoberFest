import java.util.*;
public class _17 {
    static class node{
        int data; 
        node prev, next;
        node(int x)
        {
            data=x;
        }
    }
    static node InsertBegin(node head, int data)
    {
        node curr=new node(data);
        if(head==null)
        return curr;
        else
        {
            curr.next=head;
            head.prev=curr;
            head=curr;
            return head;
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
    public static void main(String[] args) {
        System.out.println("How many elements do you want to enter");
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        node head=null;
        for(int i=0;i<n;i++)
        {
            System.out.println("Enter element");
            head=InsertBegin(head, sc.nextInt());
            printList(head);
        }
    }
}
