import java.util.Scanner;
public class _20 {
    static class node{
        int data;
        node next,prev;
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
    static node Delete(node head, int pos)
    {
        node temp=null;
        if(pos == 1)
        {
            temp=head.next;
            temp.prev=null;
            head.next=null;
            return temp;
        }
        int c=1;
        node curr=head;
        boolean y=false;
        while(curr.next!=null)
        {
            if(pos==c)
            {
                curr.prev.next=curr.next;
                curr.next.prev=curr.prev;
                y=true;
            }
            c++;
            curr=curr.next;
        }
        if(y==false)
        {
            curr.prev.next=null;
            curr.prev=null;
        }
        return head;
    }
        public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            node pb=new node(100);
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
            System.out.println("Enter position of element you want to delete");
            int pos=sc.nextInt();
            head=Delete(head, pos);
            printList(head);
        }
    }


