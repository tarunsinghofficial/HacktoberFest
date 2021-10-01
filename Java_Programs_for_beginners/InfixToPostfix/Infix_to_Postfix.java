/*
 * Infix expression to Postfix expression using stack 
 * You can also display what is in stack at each step
 * Author  Krishna Pai
 * Date    1-Oct-2021
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;

class MyCharStack{
    public char[] chStack = new char[30];
    public int top=-1;
    public int max=30;

    public boolean isStackFull() {
        return top > max - 1;
    }
    public boolean isStackEmpty() {
        return top < 0;
    }

    public void push(char c) {
        top++;
        if (isStackFull()) {
            top--;
            System.out.println("***Stack is full***");
        }
        else {
            chStack[top]= c;
        }
    }
    public char pop() {
        if (isStackEmpty()) {
            System.out.println("Stack is empty");
            return 0;
        } else {
            char topElement = chStack[top];
            top--;
            return topElement;
        }
    }
    public char peek() {
            return chStack[top];
    }
    public void display(){
        System.out.print("Stack: ");
        for (int i = 0; i<= top ; i++) {
            System.out.print(chStack[i]+ "  ");
        }
        System.out.println("\n-------------------------------");
    }
}

public class Infix_to_Postfix {
    static MyCharStack op = new MyCharStack();

    public static void main(String[] args) throws Exception {
        System.out.println("----Infix to Postfix Conversion----");
        System.out.println("Enter prefix expression: ");
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String infix = br.readLine();
        String temp = infix.replace(" ", "");

        System.out.println("*******************************");
        System.out.println("Postfix Expression: "+ Output(temp));
    }

    static int precedence(char z) {
        if (z == '+' || z == '-') {
            return 1;
        }
        if (z == '*' || z == '/' || z == '%') {
            return 2;
        }
        if (z == '^' || z == '$') {
            return 3;
        }
        return 0;
    }


    static String Output(String infix) {
        StringBuilder postfix = new StringBuilder();
        char c;
        for (int i = 0; i < infix.length(); i++) {
            c = infix.charAt(i);

            if (Character.isLetter(c)) {
                postfix.append(c);
                //System.out.println("Output: " + postfix);
            }

            else if (c == '(') {
                op.push(c);
                //op.display();
            }

            else if (c == ')'){

                while (op.peek() != '(') {
                    postfix.append(op.pop());
                }
                op.pop();
               // op.display();
            }

            else {
                while (!op.isStackEmpty() && !(op.peek() == '(') && precedence(c) <= precedence(op.peek()))
                    postfix.append(op.pop());
                op.push(c);
                //op.display();
            }
        }
        while (!op.isStackEmpty())
            postfix.append(op.pop());
        return postfix.toString();
    }
}



