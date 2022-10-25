import java.util.*;
class swap
{
    public static void main()
    {
        Scanner sc=new Scanner(System.in);
        System.out.println("Enter the two numbers");
        int a=sc.nextInt();
        int b=sc.nextInt();
        int c;
        System.out.println("Before Swapping");
        System.out.println("First Number is : "+a);
        System.out.println("Second Number is : "+b);
        System.out.println("After Swapping");
        c=a;
        a=b;
        b=c;
        System.out.println("First Number is : "+a);
        System.out.println("Second Number is : "+b);
    }
}