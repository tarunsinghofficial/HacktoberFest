
import java.util.Arrays;
import java.util.Stack;

class ReverseWord {

    // Function to reverse the words
    // of the given sentence
    static void reverse(String k)
    {

        // Create an empty character array stack
        Stack<String> s = new Stack<>();
        String[] token = k.split(" ");

        // Push words into the stack
        for (int i = 0; i < token.length; i++) {
            s.push(token[i]);
        }

        while (!s.empty()) {

            // Get the words in reverse order
            System.out.print(s.peek() + " ");
            s.pop();
        }
    }

    // Driver code
    public static void main(String[] args)
    {
        String k = "I like To fun" ;
        reverse(k);
    }
}
