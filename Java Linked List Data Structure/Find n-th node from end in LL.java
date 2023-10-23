import java.util.*;
public class _34 {
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
            System.out.print(head.data+"    ");
            head=head.next;
        }
    }
   public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);

    node head=null;
    System.out.println("Enter first element");
    int x=sc.nextInt();
    head=new node(x);
    node curr=head;
    int c=1;
    System.out.println("If you do not wish to enter element, enter -1");
    do{
        System.out.println("\nEnter element");
        x=sc.nextInt();
        if(x==-1)
        break;
        c++;
        node temp=new node(x);
        curr.next=temp;
        curr=curr.next;
        printList(head);
    }while(true);
    System.out.println("Enter the position where you want to delete element from end");
    int pos=sc.nextInt();
    if(c-pos+1<=0)
    System.out.println("The position you entered is incorrect");
    /*   METHOD-1
    else
    {
        for(int i=0;i<c-pos;i++)
        head=head.next;
        System.out.println(head.data);
    }
    */
    else{
        node temp1=head, temp2=head;
        for(int i=0;i<pos-1;i++)
        temp1=temp1.next;
        while(temp1.next!=null)
        {temp2=temp2.next;
            temp1=temp1.next;}
        System.out.println(temp2.data);

    }
   } 
}
