import java.util.*;
public class Stack {
    static int arr[] = new int[5];
    static int updated[];
    static int top = 0;
    static Scanner sc = new Scanner(System.in);
    public static void push() {
        if (top < arr.length) {
            System.out.println("Enter number");
            int a = sc.nextInt();
            arr[top] = a;
            top++;
        } else {
            System.out.println("Array is full");
        }
    }
    public static void pop() {
        if (top > 0) {
            top--;
        } else {
            System.out.println("Empty Stack");
        }
    }
    public static void display() {
        for (int i = 0; i < top; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
    public static void main(String[] args) {
        System.out.println("Enter 1 to push an element");
        System.out.println("Enter 2 to pop an element");
        System.out.println("Enter 3 to display elements");
        System.out.println("Enter 4 to exit");
        int x = sc.nextInt();
        switch (x) {
            case 1:
                push();
                main(args);
                break;
            case 2:
                pop();
                main(args);
                break;
            case 3:
                display();
                main(args);
                break;
            case 4:
                break;
            default:
                System.out.println("Enter a valid number");
                main(args);
                break;
        }
        sc.close();
    }
}
