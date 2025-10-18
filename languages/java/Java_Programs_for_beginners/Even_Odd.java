import java.util.Scanner;

class CheckEvenOdd
{
  public static void main(String args[])
  {
    int num;
    System.out.println("Enter an Integer number:");

    //The input provided by user is stored in num
    Scanner input = new Scanner(System.in);
    num = input.nextInt();

    /* If number is divisible by 2 then it's an even number
     * else odd number*/
    int r=num%10;
    if (num<0)
        System.out.println("Entered number is neither even nor odd");
     else if( r==0||r==2||r==4||r==6||r==8 )
        System.out.println("Entered number is even");
       else
        System.out.println("Entered number is odd");
  }
}
