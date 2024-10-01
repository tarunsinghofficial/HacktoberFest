import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.Scanner;

public class MergeSortLinkedList3524 {
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

    // Function to perform Merge Sort on the linked list
    public Node mergeSort(Node head) {
        if (head == null || head.next == null) {
            return head;
        }

        // Find the middle of the linked list
        Node middle = findMiddle(head);
        Node middleNext = middle.next;
        middle.next = null;

        // Recursively sort the left and right halves
        Node left = mergeSort(head);
        Node right = mergeSort(middleNext);

        // Merge the sorted halves
        return merge(left, right);
    }

    // Function to find the middle of the linked list
    private Node findMiddle(Node head) {
        if (head == null) {
            return null;
        }

        Node slow = head;
        Node fast = head;

        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        return slow;
    }

    // Function to merge two sorted linked lists
    private Node merge(Node left, Node right) {
        if (left == null) {
            return right;
        }
        if (right == null) {
            return left;
        }

        if (left.data < right.data) {
            left.next = merge(left.next, right);
            return left;
        } else {
            right.next = merge(left, right.next);
            return right;
        }
    }

    public static void main(String[] args) {
        // Code for getting the current date and time
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        System.out.println("2021503524  " + "Mugundh J B  " + dtf.format(now));

        Scanner in = new Scanner(System.in);
        MergeSortLinkedList3524 list = new MergeSortLinkedList3524();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter no of elements in Linked list: ");
        int n = scanner.nextInt();

        System.out.print("Enter the elements of Linked list: ");

        for (int i = 0; i < n; i++) {
            int element = scanner.nextInt();
            list.insertAtEnd(element);
        }

        System.out.print("Original ");
        list.display();

        // Perform Merge Sort on the linked list
        list.head = list.mergeSort(list.head);

        System.out.print("Sorted ");
        list.display();

    }
}
