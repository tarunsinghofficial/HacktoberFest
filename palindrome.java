import java.util.*;
class palindrome
{
    public static void main()
    {
    Scanner sc= new Scanner(System.in);
    System.out.println("enter a number");
    int num= sc.nextInt();
    int d,num1,rev;rev=0;
    num1=num;
    while(num!=0)
    {
        d=num%10;
        rev=rev*10+d;
        num=num/10;
    }
    if(num1==rev)
    System.out.println("the number is palindromic");
    else
    System.out.println("the number is not palindromic");
}
}


    
        
    
