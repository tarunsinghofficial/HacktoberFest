import java.util.Scanner;
public class doublelink {
    static Scanner in=new Scanner(System.in);
    public static class node{
        int data;
        node next,prev;
        node(){
            next=null;
            prev=null;
        }
    }
    public static class link{
        static node head=null;
        static node tail=null;
        public static void insert(){
            node news=new node();
            System.out.println("Enter number");
            news.data=in.nextInt();
            if(head==null){
                head=news;
                tail=news;
                System.out.println("Element added successfully");
            }
            else if(head.next==null){
                head.next=news;
                news.prev=head;
                news.next=null;
                tail=news;
                System.out.println("Element added successfully");
            }
            else{
                int a;
                System.out.println("Enter position");
                a=in.nextInt();
                if(a<0){
                    System.out.println("Posititon cannot be negative");
                }
                else if(a==0){
                    news.next=head;
                    head.prev=news;
                    head=news;
                    System.out.println("Element added successfully");
                }
                else{
                    boolean b=true;
                    node temp=head;
                    int c=-1;
                    while(temp!=null){
                        c++;
                        if(c==a-1){
                            b=true;
                            break;
                        }
                        else{
                            b=false;
                        }
                        temp=temp.next;
                    }
                    if(b){
                        if(temp.next==null){
                            tail.next=news;
                            news.prev=tail;
                            tail=news;
                            System.out.println("Element added successfully");
                        }
                        else{
                            news.next=temp.next;
                            temp.next.prev=news;
                            news.prev=temp;
                            temp.next=news;
                            System.out.println("Element added successfully");
                        }
                    }
                    else{
                            System.out.println("Position not found");
                    }
                }
            }
        }
        public static void deletion(){
            if(head==null){
                System.out.println("List is empty");
            }
            else if(head.next==null){
                node temp=head;
                head=null;
                temp=null;
                tail=head;
                System.out.println("Element deleted successfully");
            }
            else{
                int a;
                System.out.println("Enter position");
                a=in.nextInt();
                if(a<0){
                    System.out.println("Position cannot be negative");
                }
                else if(a==0){
                    node temp=head;
                    head=head.next;
                    head.prev=null;
                    temp.next=null;
                    temp=null;
                    System.out.println("Element deleted successfully");
                }
                else{
                    boolean b=true;
                    int c=-1;
                    node temp=head;
                    while(temp!=null){
                        c++;
                        if(c==a-1){
                            b=true;
                            break;
                        }
                        else{
                            b=false;
                        }
                        temp=temp.next;
                    }
                    if(b){
                        if(temp.next==tail){
                            temp.next=null;
                            tail.prev=null;
                            tail=temp; 
                            System.out.println("Element deleted successfully");
                        }
                        else{
                            temp.next=temp.next.next;
                            temp.next.prev=temp;
                            System.out.println("Element deleted successfully");
                        }
                    }
                    else{
                        System.out.println("Element deleted successfully");
                    }
                }
            }
        }
        public static void display(){
            if(head==null){
                System.out.println("List is empty");
            }
            else{
                node temp=head;
                while(temp!=null){
                    System.out.println(temp.data);
                    temp=temp.next;
                }
            }
        }
    }
    public static void main(String[] args){
        int a;
        link l=new link();
        while(true){
            System.out.println("Enter 1-add");
            System.out.println("Enter 2-delete");
            System.out.println("Enter 3-display");
            System.out.println("Enter 4-exit");
            a=in.nextInt();
            switch(a){
                case 1:
                l.insert();
                break;
                case 2:
                l.deletion();
                break;
                case 3:
                l.display();
                break;
                case 4:
                System.exit(0);
                break;
                default:
                System.out.println("No match to your selection");
                break;
            }
        }
    }
}
