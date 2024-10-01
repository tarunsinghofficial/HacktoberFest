import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class LinkedListRemDuplicates3524 {
    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    Node head;

    // Function to insert a node at the end of the linked list
    public void insertAtEnd(int data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = newNode;
            return;
        }
        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode;
    }

    // Function to display the linked list
    public void display() {
        System.out.print("Linked List:\n");
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.print("NULL");
        System.out.println();
    }

    public void removeDuplicates(){
        if(head == null || head.next == null) // If no element or only one element, no possibility for duplicates
            return;
        Node curNode = head;
        while(curNode.next != null){ // Outer traversal
            Node nextNode = curNode;
            while(nextNode.next != null){ // Inner traversal for next right elements of current node
                if(nextNode.next.data == curNode.data) {
                    nextNode.next = nextNode.next.next;
                }
                else
                    nextNode = nextNode.next;
            }
            curNode = curNode.next; // Moving to next node
        }
    }

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        LinkedListRemDuplicates3524 list = new LinkedListRemDuplicates3524();
        Scanner in = new Scanner(System.in);

        System.out.print("Enter no of elements in Linked list: ");
        int n = in.nextInt();

        System.out.print("Enter the elements of Linked list: ");

        for (int i = 0; i < n; i++) {
            int element = in.nextInt();
            list.insertAtEnd(element);
        }

        System.out.println("\nBefore removing Duplicates: ");
        list.display();

        list.removeDuplicates();

        System.out.println("\nAfter removing Duplicates: ");
        list.display();
    }

}
