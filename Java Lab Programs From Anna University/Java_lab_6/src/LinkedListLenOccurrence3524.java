import java.util.Scanner;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class LinkedListLenOccurrence3524 {
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
        Node cur = head;
        while (cur.next != null) {
            cur = cur.next;
        }
        cur.next = newNode;
    }

    // Function to display the linked list
    public void display() {
        System.out.print("Linked List: ");
        Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.print("NULL");
        System.out.println();
    }

    // Function to calculate the length of the linked list
    public int len() {
        if (head == null) // If head is null, then length is 0
            return 0;
        int count = 1;
        Node cur = head;
        while (cur.next != null) {
            cur = cur.next;
            count += 1; // Counting the no of nodes
        }
        return count;
    }

    // Function to count the occurrences of a specific data value in the linked list
    public int countOccurrence(int data) {
        if (head == null) // If head is null, then occurrence is 0
            return 0;
        int count = 0;
        Node cur = head;
        while (cur != null) {
            if (cur.data == data)
                count += 1; // Counting the occurrence
            cur = cur.next;
        }
        return count;
    }

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);
        LinkedListLenOccurrence3524 list = new LinkedListLenOccurrence3524();
        int choice, data;

        System.out.println("\nChoose an operation:");
        System.out.println("1. Insert at the end");
        System.out.println("2. Calculate the length of the linked list");
        System.out.println("3. Count the occurrences of a specific value");
        System.out.println("4. Display the linked list");
        System.out.println("5. Exit");

        while (true) {
            System.out.print("\nEnter your choice: ");
            choice = in.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the value to insert at the end: ");
                    data = in.nextInt();
                    list.insertAtEnd(data);
                    break;

                case 2:
                    int length = list.len();
                    System.out.println("Length of the linked list: " + length);
                    break;

                case 3:
                    System.out.print("Enter the value to count occurrences: ");
                    data = in.nextInt();
                    int occurrence = list.countOccurrence(data);
                    System.out.println("Occurrences of " + data + ": " + occurrence);
                    break;

                case 4:
                    list.display();
                    break;

                case 5:
                    System.out.print("Exiting!");
                    System.exit(0);
                    break;

                default:
                    System.out.print("Invalid choice. Please try again.");
                    break;
            }
        }
    }
}
