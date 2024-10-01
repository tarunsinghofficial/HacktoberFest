import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class LinkedListDeletion3524 {
    static class Node {
        int data;
        Node next;

        Node(int d) {
            data = d;
            next = null;
        }
    }

    Node head;

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

    // Function to delete the first node (beginning) of the linked list
    public void deleteFromBeginning() {
        if (head == null) {
            System.out.println("Linked list is empty. Nothing to delete.");
            return;
        }
        head = head.next; // Update the head to the next node, effectively removing the first node.
    }

    // Function to delete the last node (end) of the linked list
    public void deleteFromEnd() {
        if (head == null) {
            System.out.println("Linked list is empty. Nothing to delete.");
            return;
        }
        if (head.next == null) {
            head = null; // If there is only one node, set head to null.
            return;
        }
        Node current = head;
        Node previous = null;
        while (current.next != null) {
            previous = current;
            current = current.next;
        }
        previous.next = null; // Set the next of the second-to-last node to null.
    }

    // Function to delete a node with a specific value from the linked list
    public void deleteByValue(int targetData) {
        if (head == null) {
            System.out.println("Linked list is empty. Nothing to delete.");
            return;
        }
        if (head.data == targetData) {
            head = head.next; // If the target data is in the first node, update the head.
            return;
        }
        Node current = head;
        Node previous = null;
        while (current != null) {
            if (current.data == targetData) {
                previous.next = current.next; // Skip the current node to remove it.
                return;
            }
            previous = current;
            current = current.next;
        }
        System.out.println("Element with value " + targetData + " not found.");
    }

    // Function to delete a node at a specific position from the linked list
    public void deleteByPosition(int pos) {
        if (head == null) {
            System.out.println("Linked list is empty. Nothing to delete.");
            return;
        }
        if (pos <= 0) {
            System.out.println("Invalid position. Please provide a positive position.");
            return;
        }
        if (pos == 1) {
            head = head.next; // If deleting the first node, update the head.
            return;
        }
        Node current = head;
        Node previous = null;
        int count = 1;
        while (current != null) {
            if (count == pos) {
                previous.next = current.next; // Skip the current node to remove it.
                return;
            }
            previous = current;
            current = current.next;
            count++;
        }
        System.out.println("Position " + pos + " is out of range.");
    }

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));
        Scanner in = new Scanner(System.in);
        LinkedListDeletion3524 list = new LinkedListDeletion3524();
        int choice, data, position;

        System.out.println("\nChoose an operation:");
        System.out.println("1. Insert at the end");
        System.out.println("2. Delete from the beginning");
        System.out.println("3. Delete from the end");
        System.out.println("4. Delete by value");
        System.out.println("5. Delete by position");
        System.out.println("6. Exit");

        while (true) {
            System.out.print("\nEnter your choice: ");
            choice = in.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("Enter the value to insert at the end: ");
                    data = in.nextInt();
                    list.insertAtEnd(data);
                    list.display();
                    break;

                case 2:
                    list.deleteFromBeginning();
                    list.display();
                    break;

                case 3:
                    list.deleteFromEnd();
                    list.display();
                    break;

                case 4:
                    System.out.print("Enter the value to delete: ");
                    data = in.nextInt();
                    list.deleteByValue(data);
                    list.display();
                    break;

                case 5:
                    System.out.print("Enter the position to delete: ");
                    position = in.nextInt();
                    list.deleteByPosition(position);
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
