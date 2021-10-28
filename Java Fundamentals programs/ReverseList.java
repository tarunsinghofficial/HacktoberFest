//Java program to create a doubly linked list of n nodes and display it in reverse order
public class ReverseList {  


    class Node{  
        int data;  
        Node previous;  
        Node next;  

        public Node(int data) {  
            this.data = data;  
        }  
    }  


    Node head, tail = null;  

    public void addNode(int data) {  

        Node newNode = new Node(data);  

        if(head == null) {  

            head = tail = newNode;  

            head.previous = null;  

            tail.next = null;  
        }  
        else {  

            tail.next = newNode;  

            newNode.previous = tail;  

            tail = newNode;  

            tail.next = null;  
        }  
    }  


    public void reverse() {  

        Node current = head, temp = null;  


        while(current != null) {  
            temp = current.next;  
            current.next = current.previous;  
            current.previous = temp;  
            current = current.previous;  
        }  

        temp = head;  
        head = tail;  
        tail = temp;  
    }  

    public void display() {  

        Node current = head;  
        if(head == null) {  
            System.out.println("List is empty");  
            return;  
        }  

        while(current != null) {  


            System.out.print(current.data + " ");  
            current = current.next;  
        }  
    }  

    public static void main(String[] args) {  

        ReverseList dList = new ReverseList();  

        dList.addNode(1);  
        dList.addNode(2);  
        dList.addNode(3);  
        dList.addNode(4);  
        dList.addNode(5);  

        System.out.println("Original List: ");  
        dList.display();  


        dList.reverse();  

        //Displays the reversed list  
        System.out.println("\nReversed List: ");  
        dList.display();  
    }  
}