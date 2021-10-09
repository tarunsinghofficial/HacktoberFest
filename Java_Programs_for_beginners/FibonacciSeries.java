// Program for printing fibonacci series

import java.util.Scanner;

public class FibonacciSeries {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter term while you want to print FibonacciNumbers : ");
		int n = sc.nextInt(), a = 0, b=1;
		System.out.print(a+" "+b+" ");
		int c = 0;
		for (int i=0; i<n-2; i++) {
			c = a+b;
			System.out.print(c+" ");
			a = b;
			b=c;
			
		}

	}

}
