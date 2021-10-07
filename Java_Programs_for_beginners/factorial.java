import java.util.*;
class factorial
{  
	static int factorial(int n){    
	if (n == 0)    
		return 1;    
	else    
		return(n * factorial(n-1));    
	}    
	public static void main(String args[]){  
	Scanner sc = new Scanner(System.in);
	int number = sc.nextInt();
	int i,fact=1;      
	fact = factorial(number);   
	System.out.println(number+" : "fact);    
	}
}  
