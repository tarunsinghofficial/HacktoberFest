import java.util.*;

public class _13 {
    static class node {
        int data;
        node next;

        node(int x) {
            data = x;
        }
    }

    // static node InsertEnd(node head, int x) {
    //     node curr = new node(x);
    //     if (head == null) {
    //         head = curr;
    //         return head;
    //     }
    //     node temp = head;
    //     while (temp.next != null)
    //         temp = temp.next;
    //     temp.next = curr;
    //     return head;
    // }

    static node Insert(node head, int x, int pos) {
        node curr = new node(x);
        if (pos == 1) {
            curr.next = head;
            head = curr;
            return head;
        } else {
            int c = 2;
            node temp = head;
            while (pos != c) {
                c++;
                temp = temp.next;
            }
            node temp1 = temp.next;
            temp.next = curr;
            curr.next = temp1;
            return head;
        }
    }

    static void Search(node head) {
        Scanner sc = new Scanner(System.in);
        int x;
        System.out.println();
        System.out.println("If you want to exit, enter -1");
        do {
            System.out.println("Enter the element you want to search.");
            x = sc.nextInt();
            node temp = head;
            int c = 0;
            boolean y = false;
            while (temp != null) {
                c++;
                if (temp.data == x) {
                    System.out.println("The value +" + x + " is found at " + c);
                    y = true;
                }
                temp = temp.next;
            }
            if (y == false && x != -1)
                System.out.println("Element not found");
            y = false;
            c = 0;
        } while (x != -1);
    }

    static node Delete(node head, int pos) {
        if (pos == 1) {
            head = head.next;
            return head;
        } else {
            int c = 2;
            node temp = head;
            while (temp.next != null) {
                if (pos == c && temp.next.next != null) {
                    temp.next = temp.next.next;
                    break;
                } else if (temp.next.next == null)
                    {temp.next = null;
                        break;}
                temp = temp.next;
            }
            return head;
        }
    }

    static void PrintList(node head) {
        while (head != null) {
            System.out.print(head.data + " ");
            head = head.next;
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
        node turr=null;
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
                 turr=head;
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
        System.out.println("If you want to search element, press 1.");
        int t=sc.nextInt();
        if(t==1)
        Search(head);
    System.out.println(turr.data);
        System.out.println("If you want to delete element, press 2.");
        t=sc.nextInt();
        
        if(t==2)
        {
            System.out.println("Enter the position where you want to delete the element.");
            int pos=sc.nextInt();
            if(pos>m || pos<=0)
            System.out.println("The position you entered is incorrect.");
            else
            {

            do{
            turr=Delete(turr, pos);
            PrintList(turr);
                 m--; 
                 System.out.println("Enter the position where you want to delete the element. To exit, press -1");
                 pos=sc.nextInt();
                }while(m>1 && pos!=-1);
             } }
    }
}
