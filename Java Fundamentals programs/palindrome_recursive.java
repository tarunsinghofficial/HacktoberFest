import java.util.*; 
public class palindrome_recursive
{
// recursive function that 
// returns the reverse of digits
static int rev(int n, int temp)
{
    // base case
    if (n == 0)
        return temp;
 
    // stores the reverse
    // of a number
    temp = (temp * 10) + (n % 10);
 
    return rev(n / 10, temp);
}
 
// Driver Code
public static void main (String[] args) 
{
    int n = 121;
    int temp = rev(n, 0);
     
    if (temp == n)
        System.out.println("Yes");
    else
        System.out.println("No");
}
}