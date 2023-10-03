import java.util.Scanner;

public class stringpalindrome {
    public static void main(String[] args) {
        Scanner scanner=new Scanner(System.in);
        System.out.println("Enter a string as an input to check whether it is palindrome or not");
        String input= scanner.nextLine();
        scanner.close();
        //checking whether palindrome or not
        if(isPalindrome(input))
            System.out.println(input+" is a palindrome string");    
        else        
            System.out.println(input+" is not a palindrome string");        
    }
 
    public static boolean isPalindrome(String str) {
        int left = 0, right = str.length() - 1;
        
        while(left < right)
        {
            if(str.charAt(left) != str.charAt(right))            
                return false;
            
            left++;
            right--;
        }
        return true;    }    }
    

