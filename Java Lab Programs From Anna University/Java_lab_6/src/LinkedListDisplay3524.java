import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class LinkedListDisplay3524 {
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
            head = newNode; // If the list is empty, set the new node as the head
            return;
        }

        Node current = head;
        while (current.next != null) {
            current = current.next;
        }
        current.next = newNode; // Traverse the list to find the last node and append the new node
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

    // Function to display the linked list in reverse order using recursion
    public void displayReverse(Node node) {
        if (node == null) {
            return; // Base case for recursion
        }
        displayReverse(node.next); // Recursively call the function for the next node
        System.out.print(node.data + " -> "); // Print the data of the current node during backtracking
    }

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));
        Scanner in = new Scanner(System.in);
        LinkedListDisplay3524 list = new LinkedListDisplay3524();
        int choice, data;

        System.out.println("\nChoose an operation:");
        System.out.println("1. Insert at the end");
        System.out.println("2. Display linked list");
        System.out.println("3. Display linked list in reverse");
        System.out.println("4. Exit");

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
                    list.display();
                    break;

                case 3:
                    System.out.print("Linked List in Reverse: ");
                    list.displayReverse(list.head);
                    System.out.print("NULL\n");
                    break;

                case 4:
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
