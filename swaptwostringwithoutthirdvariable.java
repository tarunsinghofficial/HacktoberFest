// Java program to swap two strings without using a temporary variable.
import java.util.*;
import java.io.*;
class Swapping
{
	public static void main(String args[])
	{
		// Declare two strings
		String x = "Hello";
		String y = "World";
		
		// Print String before swapping
		System.out.println("Strings before swap: a = " +
									x + " and b = "+y);
		
		// append 2nd string to 1st
		x = x + y;
		
		// store initial string a in string b
		x = y.substring(0,x.length()-y.length());
		
		// store initial string b in string a
		x = x.substring(y.length());
		
		// print String after swapping
		System.out.println("Strings after swap: x = " +
									x + " and y = " + y);	
	}
}
