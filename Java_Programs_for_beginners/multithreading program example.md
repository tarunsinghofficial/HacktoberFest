Ques- Demonstrate multithreading by creating two threads, one for printing the odd numbers and the other for printing
even numbers with in a given range of your choice

code-

PROGRAM 1:

package packsaurabh; public class Prime { public static boolean checkPrime(int num) { int temp; boolean isPrime = true;
for (int i = 2; i <= num / 2; i++)
{temp = num % i; if (temp == 0)
{isPrime = false;break;}} return isPrime;} }

PROGRAM 2:

package mypack; import packsaurabh.*; import java.util.Scanner; public class TwinsPrime { public static void main(String
args[]) { int i; Scanner sc = new Scanner(System.in); System.out.print("Enter first number: "); int n1 = sc.nextInt();
System.out.print("Enter second number: "); int n2 = sc.nextInt(); sc.close(); System.out.println("Twin prime numbers
are: "); for(i = n1; i <= n2; i++) { if(Prime.checkPrime(i) & Prime.checkPrime(i+2) & i > 1)
{System.out.println("(" + i + "," + (i+2) + ")");}}}}

RUN THE CODE:

javac -d . Prime.java

javac -d . TwinsPrime.java

java mypack.TwinsPrime

 
