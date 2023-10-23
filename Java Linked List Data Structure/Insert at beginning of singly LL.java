import java.util.*;

import javax.swing.text.DefaultEditorKit.InsertBreakAction;
public class _8 {
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
            System.out.println(head.data);
            head=head.next;
        }
    }

    static node InsertBegin(node head, int x)
    {
        node temp=new node(x);
        temp.next=head;
        return temp;
    }
        public static void main(String[] args) {
            // node head=new node(10);
            // head.next=new node(20);
            // head.next.next=new node(30);
            // printList(head);
            // System.out.println("If you want to add element at beginning at starting, press 1.");
            // Scanner sc=new Scanner(System.in);
            // int t=sc.nextInt();
            // if(t==1)
            // {
            //     node curr=new node(sc.nextInt());
            //     curr.next=head;
            //     head=curr;
            //     printList(head);
            node head=null;
            head=InsertBegin(head,30);
            head=InsertBegin(head,20);
            head=InsertBegin(head,10);
            printList(head);
            }

        }

