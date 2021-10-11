package com.company;

import java.util.Scanner;
import java.util.Stack;

public class BalanceBracket {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        String str = in.nextLine();


        System.out.println(isBalances(str));


    }



        public static boolean isBalances(String str) {
            Stack<Character> st = new Stack<>();
            for (int i = 0; i < str.length(); i++) {
                char ch = str.charAt(i);
                if (ch == '(' || ch == '{' || ch == '[') {
                    st.push(ch);

                } else {
                    if (st.empty()==true){
                        return false;
                    }else if (isMatching(st.peek(),ch)==false){
                        return false;
                    }else {
                        st.pop();
                    }
                }

                }
             return (st.empty()==true);         //for extra opening  bracket
            }

    public static boolean isMatching(Character a, char b) {
        return ((a=='(' &&b==')')||
                (a=='{' &&b=='}')||
                (a=='[' &&b==']'));
    }

}
