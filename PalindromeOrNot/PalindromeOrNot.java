import java.util.Scanner;

public class PalindromeOrNot {
    public static void main(String[] args) {

//      Find if a number is palindrome or not

        Scanner input = new Scanner(System.in);

        System.out.print("Enter number : ");
        int number = input.nextInt();
        int num = number;   //to store input value
        int reversedNumber = 0 ;

        while (num!=0){
            int remainder = num%10;
            num/=10;
            reversedNumber = reversedNumber*10 + remainder;
        }
        if (number == reversedNumber) System.out.println("Palindrome number");
        else System.out.println("Not Palindrome");
    }
}