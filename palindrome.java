package Java_beginners.strings;

import java.util.Scanner;

public class palindrome {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter any string to check: ");
        String str = input.nextLine();

        boolean ispalindrome =true;
        for(int i=0,j=str.length()-1; i<j; i++, j--){
            if(str.charAt(i)==str.charAt(j))
                continue;

            ispalindrome = false;
            break;
        }
        System.out.println(ispalindrome ? "Yes" : "no");

    }

}
