import java.util.ArrayList;

public class Stack {
    private ArrayList<Integer> data;
    
    public Stack() {
        data = new ArrayList<>();
    }
    
    // Push element onto stack
    public void push(int value) {
        data.add(value);
    }
    
    // Remove and return top element
    public int pop() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return data.remove(data.size() - 1);
    }
    
    // Return top element without removing
    public int peek() {
        if (isEmpty()) {
            throw new RuntimeException("Stack is empty");
        }
        return data.get(data.size() - 1);
    }
    
    // Check if stack is empty
    public boolean isEmpty() {
        return data.isEmpty();
    }
    
    // Get stack size
    public int size() {
        return data.size();
    }
    
    public static void main(String[] args) {
        Stack stack = new Stack();
        
        stack.push(10);
        stack.push(20);
        stack.push(30);
        
        System.out.println("Top element: " + stack.peek());
        System.out.println("Popped: " + stack.pop());
        System.out.println("New top: " + stack.peek());
        System.out.println("Stack size: " + stack.size());
    }
}