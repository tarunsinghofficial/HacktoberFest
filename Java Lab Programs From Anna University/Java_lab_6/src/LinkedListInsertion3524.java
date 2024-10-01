import java.util.*;
import java.time.format.DateTimeFormatter;
import java.time.LocalDateTime;

public class LinkedListInsertion3524 {
    // Inner class representing a Node in the linked list
    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    Node head; // Head of the linked list

    // Function to insert a node at the beginning of the linked list
    public void insertAtBeginning(int data) {
        Node newNode = new Node(data);
        newNode.next = head; // New node points to the current head
        head = newNode; // Update head to the new node
    }

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
        current.next = newNode; // Set the new node as the next of the last node
    }

    // Function to insert a node at a specific position in the linked list
    public void insertAtPosition(int data, int pos) {
        Node newNode = new Node(data);

        if (pos <= 0) { // Insert at the beginning
            newNode.next = head;
            head = newNode;
            return;
        }

        if (head == null) { // If the list is empty, insert at the beginning
            head = newNode;
            return;
        }

        Node current = head;
        Node previous = null;
        int count = 0;

        while (count < pos && current != null) {
            previous = current;
            current = current.next;
            count++;
        }

        if (current == null) { // Insert at the end
            previous.next = newNode;
        } else { // Insert at the specified position
            newNode.next = current;
            previous.next = newNode;
        }
    }

    // Function to insert a node after a specific node with a target data value
    public void insertAfterNode(int data, int targetData) {
        Node newNode = new Node(data);
        Node current = head;

        while (current != null) {
            if (current.data == targetData) {
                newNode.next = current.next;
                current.next = newNode;
                return;
            }
            current = current.next;
        }

        // Target node not found, insert at the end
        insertAtEnd(data);
    }

    // Function to insert a node before a specific node with a target data value
    public void insertBeforeNode(int data, int targetData) {
        Node newNode = new Node(data);

        if (head != null && head.data == targetData) {
            newNode.next = head;
            head = newNode;
            return;
        }

        Node current = head;
        Node previous = null;

        while (current != null) {
            if (current.data == targetData) {
                newNode.next = current;
                if (previous != null) {
                    previous.next = newNode;
                } else {
                    head = newNode; // If target is the head, update the head
                }
                return;
            }
            previous = current;
            current = current.next;
        }

        // Target node not found, insert at the end
        insertAtEnd(data);
    }

    // Function to display the elements of the linked list
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

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);
        LinkedListInsertion3524 list = new LinkedListInsertion3524();
        int choice, data, position, targetData;

        // Menu for user interaction
        System.out.println("\nChoose an operation:");
        System.out.println("1. Insert at the beginning");
        System.out.println("2. Insert at the end");
        System.out.println("3. Insert at a specific position");
        System.out.println("4. Insert after a specific node");
        System.out.println("5. Insert before a specific node");
        System.out.println("6. Exit");

        while (true) {
            System.out.print("\nEnter your choice: ");
            choice = in.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the value to insert at the beginning: ");
                    data = in.nextInt();
                    list.insertAtBeginning(data);
                    list.display();
                    break;

                case 2:
                    System.out.print("Enter the value to insert at the end: ");
                    data = in.nextInt();
                    list.insertAtEnd(data);
                    list.display();
                    break;

                case 3:
                    System.out.print("Enter the value to insert: ");
                    data = in.nextInt();
                    System.out.print("Enter the position to insert at: ");
                    position = in.nextInt();
                    list.insertAtPosition(data, position);
                    list.display();
                    break;

                case 4:
                    System.out.print("Enter the value to insert: ");
                    data = in.nextInt();
                    System.out.print("Enter the value after which to insert: ");
                    targetData = in.nextInt();
                    list.insertAfterNode(data, targetData);
                    list.display();
                    break;

                case 5:
                    System.out.print("Enter the value to insert: ");
                    data = in.nextInt();
                    System.out.print("Enter the value before which to insert: ");
                    targetData = in.nextInt();
                    list.insertBeforeNode(data, targetData);
                    list.display();
                    break;

                case 6:
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
