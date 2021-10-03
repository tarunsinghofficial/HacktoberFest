
import java.util.Scanner;
import java.util.Stack;


public class Main {
    public static void main(String args[]) {
        Stack stack = new Stack();

        String input;

        String trimmedInput[];
        int output;
        int number1, number2;
        int countOfNumber, j;

        Scanner scanner = new Scanner(System.in);

        System.out.println("put your arithmetical expression. Using Space between ");
        input = scanner.nextLine();

        trimmedInput = input.split("\\s+");

//       for(String a:trimmedInput)
//           System.out.println(a);


        countOfNumber = trimmedInput.length;


        for (j = 0; j < countOfNumber; j++) {

            if (isNumeric(trimmedInput[j])) {
                stack.push(trimmedInput[j]);

            }
            if (trimmedInput[j].equals("+")) {
                number1 = Integer.parseInt((String) stack.pop());

                number2 = Integer.parseInt((String) stack.pop());

                output = number1 + number2;

                stack.push(output);

            }

            if (trimmedInput[j].equals("-")) {
                number1 = Integer.parseInt((String) stack.pop());

                number2 = Integer.parseInt((String) stack.pop());

                output = number1 - number2;

                stack.push(output);
            }
            if (trimmedInput[j].equals("*")) {
                number1 = Integer.parseInt((String) stack.pop());

                number2 = Integer.parseInt((String) stack.pop());

                output = number1 * number2;

                stack.push(output);
            }
            if (trimmedInput[j].equals("/")) {
                number1 = Integer.parseInt((String) stack.pop());

                number2 = Integer.parseInt((String) stack.pop());

                output = number1 / number2;

                stack.push(output);
            }

        }

        while (!stack.isEmpty())
            System.out.println(stack.pop());


    }

    public static boolean isNumeric(String str) {
        try {
            double d = Double.parseDouble(str);
        } catch (NumberFormatException nfe) {
            return false;
        }
        return true;
    }
