import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class LinkedListSearchAccess3524 {
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
        System.out.print("Linked List: ");
        LinkedListSearchAccess3524.Node current = head;
        while (current != null) {
            System.out.print(current.data + " -> ");
            current = current.next;
        }
        System.out.print("NULL");
        System.out.println();
    }

    // Function to search for an element by value
    public int searchByValue(int targetData) {
        Node current = head;
        int position = 1;
        while (current != null) {
            if (current.data == targetData) {
                return position; // Element found, return its position
            }
            current = current.next;
            position++;
        }
        return -1; // Element not found
    }

    // Function to access an element by position
    public int accessByPosition(int pos) {
        Node current = head;
        int count = 1;
        while (current != null) {
            if (count == pos) {
                return current.data; // Return the data of the element at the specified position
            }
            current = current.next;
            count++;
        }
        // If the position is out of range, return a sentinel value (e.g., -1)
        return -1;
    }

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));
        Scanner in = new Scanner(System.in);
        LinkedListSearchAccess3524 list = new LinkedListSearchAccess3524();
        int choice, data, position;

        System.out.println("\nChoose an operation:");
        System.out.println("1. Insert at the end");
        System.out.println("2. Search for an element by value");
        System.out.println("3. Access an element by position");
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
                    System.out.print("Enter the value to search for: ");
                    data = in.nextInt();
                    int foundPosition = list.searchByValue(data);
                    if (foundPosition != -1) {
                        System.out.println("Element found at position " + foundPosition);
                    } else {
                        System.out.println("Element not found in the linked list.");
                    }
                    break;

                case 3:
                    System.out.print("Enter the position to access: ");
                    position = in.nextInt();
                    int accessedData = list.accessByPosition(position);
                    if (accessedData != -1) {
                        System.out.println("Element at position " + position + ": " + accessedData);
                    } else {
                        System.out.println("Position " + position + " is out of range.");
                    }
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
