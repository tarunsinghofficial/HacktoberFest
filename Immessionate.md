import java.util.Scanner;

class CheckEvenOdd { public static void main(String args[])
{ int num; System.out.println("Enter an Integer number:"); Scanner input = new Scanner(System.in); num = input.nextInt()
; if (num<0)
System.out.println("Entered number is neither even nor odd"); else if( num % 2 == 0 )
System.out.println("even"); else System.out.println("odd"); } }
