import java.util.*;

class Collectionss{

    //ArrayList
    public static void ArrayListConcepts(){
        ArrayList<Integer> list1= new ArrayList<Integer>();
        ArrayList<String> list2=new ArrayList<>();

        //add elements
        list1.add(0);
        list1.add(1);
        list2.add("Suraj");
        System.out.println(list1+" "+list2);

        //Get elements
        System.out.println(list1.get(1));

        //Add elements in between
        list1.add(1,2); //index then elements
        System.out.println(list1);

        //set elements
        list1.set(0,3);
        System.out.println(list1);

        //Delete element
        list1.remove(2);
        System.out.println(list1);

        //size
        System.out.println("Size is "+list1.size());

        //loop
        for(int i=0;i<list1.size();i++)
            System.out.println(list1.get(i));

        //Different
        for(Integer ele:list1)
            System.err.println("Another "+ele);

        for(Object var:list1)
            System.out.println(var);

        //Sorting
        Collections.sort(list1);
        System.out.println(list1);
    }
    

    //LinkedList
    
    class Node{
        int val;
        Node next;

        Node(int data){
            this.val=data;
            this.next=null;
        }
    }
    Node head;
    public void addFirst(int data){
        Node newnode=new Node(data);
        if(head==null){
            head=newnode;
            return;
        }

        newnode.next=head;
        head=newnode;
    }
    public void addLast(int data){
        Node newnode=new Node(data);
        if(head==null){
            head=newnode;
            return;
        }

        Node temp=head;
        while(temp.next!=null) temp=temp.next;
        temp.next=newnode;
        
    }
    public void deleteLast(){
        if(head==null){
            System.out.println("List is Empty");
        }
        if(head.next==null)
        {
            head=null;
            return;
        }

        Node secondLast=head;
        while(secondLast.next.next!=null)
            secondLast=secondLast.next;
        
        secondLast.next=null;

    }
    public void printList(){
        Node temp=head;
        while(temp!=null) {
            System.out.println(temp.val);
            temp=temp.next; 
        }       
    }

    public static void LinkedLists(){
        LinkedList<String> list= new LinkedList<>();
        list.addFirst("a");
        list.addFirst("is");
        list.addLast("Animal");
        System.out.println(list);
    }

    public static void main(String args[]) {
        System.out.println("**********************ArrayList********************************");
        ArrayListConcepts();
        Collectionss list=new Collectionss();
        System.out.println("**********************LinkedList********************************");
        list.addFirst(20);
        list.addFirst(10);
        list.addLast(30);
        list.printList();
        list.deleteLast();
        list.printList();
        LinkedLists();
    }
}

