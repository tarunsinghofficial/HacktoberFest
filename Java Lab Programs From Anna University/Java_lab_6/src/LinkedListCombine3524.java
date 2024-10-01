import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class LinkedListCombine3524 {
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

    public Node combine(LinkedListCombine3524 l2){
        if(head == null){ // If head is null, then no need to combine. Just, return 2nd LL
            return l2.head;
        }
        Node cur = head;
        while(cur.next != null){ // Traverse until end of the first LL
            cur = cur.next;
        }
        cur.next = l2.head; // Point the first LL's next to 2nd LL

        return head;
    }

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        LinkedListCombine3524 list1 = new LinkedListCombine3524();
        LinkedListCombine3524 list2 = new LinkedListCombine3524();
        LinkedListCombine3524 combined = new LinkedListCombine3524();
        Scanner in = new Scanner(System.in);

        System.out.print("Enter no of elements in Linked list 1: ");
        int n = in.nextInt();

        System.out.print("Enter the elements of Linked list: ");

        for (int i = 0; i < n; i++) {
            int element = in.nextInt();
            list1.insertAtEnd(element);
        }

        System.out.print("\nEnter no of elements in Linked list 2: ");
        n = in.nextInt();

        System.out.print("Enter the elements of Linked list: ");

        for (int i = 0; i < n; i++) {
            int element = in.nextInt();
            list2.insertAtEnd(element);
        }


        combined.head = list1.combine(list2);
        System.out.print("Combined ");
        combined.display();
    }
}
