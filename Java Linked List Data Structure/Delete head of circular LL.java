import java.util.*;
public class _29 {
    static class node{
        int data; 
        node next;
        node(int x)
        {
            data=x;
        }
    }
    static node Insert(node head, int x, int pos)
    {
        node temp=new node(x);
        if(head==null)
        {
            temp.next=temp;
            return temp;
        }
        else if(pos==1)
        {
            temp.next=head.next;
            head.next=temp;
            int t=head.data;
            head.data=temp.data;
            temp.data=t;
            return head;
        }
        else 
        {
            node curr=head;
            int c=2;
            boolean p=true;
            while(curr!=head || p)
            {
                p=false;
                if(pos==c)
                {
                    temp.next=curr.next;
                    curr.next=temp;
                    break;
                }
                curr=curr.next;c++;
            }
            return head;
        }
    }
    static node Delete(node head, int pos)
    {
        if(head.next==head)
        return null;
        else{
            node curr=head;
            int c=2;
            while(curr.next!=head)
            {
                if(pos==c)
                {
                    curr.next=curr.next.next;
                    break;
                }
                c++;
                curr=curr.next;
            }
            if(pos==1)
            {
                curr.next=curr.next.next;
                return curr.next;
            }
            else return head;
        }
    }
    static node reverse(node head)
    {
        node temp1=head.next, prev=null;
        while(temp1!=null)
        {
            head.next=prev;
            prev=head;
            head=temp1;
            temp1=temp1.next;
            printList(head);
        }
        System.out.println(prev.data);
        head.next=prev;
        return head;
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
public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    node head=null;
    System.out.println("If you want to delete elements, enter 'D'.\nIf you want to enter elements, enter 'E'");
System.out.println("Since this is your first input, 'E' is selected by default");
char ch='E';
int x,pos=1,c=0;
do{
    if(ch=='E')
    {
    do{
        if(c==0)
        {
            System.out.println("Please enter an element. Also, if you want to stop inserting, press '-1' as input;");
             x=sc.nextInt();
            head=Insert(head,x, pos);
            c++;
            printList(head);
        }
        else
        {
            System.out.println();
            System.out.println("Enter element.");
            x=sc.nextInt();
            if(x==-1)
            break;
            System.out.println("Enter position");
            pos=sc.nextInt();
            if(pos>c +1 || pos<1)
            System.out.println("The position you entered is INCORRECT. Please re-enter.");
            c++;
            Insert(head, x, pos);
            printList(head);
        }
    }while(x!=-1);
        System.out.println("Do you wish to delete some elements. If yes, press 'D'. To exit, press 'F'");
        ch=sc.next().charAt(0);
}
if(ch=='D')
{
    do{
        System.out.println("Enter the position from where you want to delete element");
        pos=sc.nextInt();
        // if(pos==-1)
        // break;
        if(pos>c || pos<0)
        {if(pos!=-1)
        System.out.println("The position you entered is incorrect. Please re-enter");}
        else
        {
            head=Delete(head, pos);
            c--;
            if(head!=null)
            printList(head);
        }
        if(c==0)
        {
            System.out.println("All the elements have been deleted. If you like to add some, press 'E' or if you like to exit, press 'F'.");
            ch=sc.next().charAt(0);
            break;
        }
    }while(pos!=-1);
    System.out.println("If you wish to enter elements, press 'E' else press 'F' to exit.");
    ch=sc.next().charAt(0);
}

}while(ch!='F');
      head= reverse(head);
      printList(head);
}
}


