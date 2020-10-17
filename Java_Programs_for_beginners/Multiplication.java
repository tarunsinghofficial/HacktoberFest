import java.util.*;
   
class Multiplication{ 
       
    static String multiply(String number1, String number2){ 
        
        int l1 = number1.length(); 
	    int l2 = number2.length(); 
	    if (l1 == 0 || l2 == 0) 
		    return "0"; 

	    int result[] = new int[l1 + l2]; 

	    int i_n1 = 0; 
	    int i_n2 = 0; 
	
	    for (int i = l1 - 1; i >= 0; i--){ 
		    int carry = 0; 
		    int n1 = number1.charAt(i) - '0'; 

		    i_n2 = 0; 
		
				 
		    for (int j = l2 - 1; j >= 0; j--){ 
			
			    int n2 = number2.charAt(j) - '0'; 

			    int sum = n1 * n2 + result[i_n1 + i_n2] + carry; 

			    carry = sum / 10; 

    			result[i_n1 + i_n2] = sum % 10; 

	    		i_n2++; 
		    } 

		
		    if (carry > 0) {
			    result[i_n1 + i_n2] += carry; 
            }
		    i_n1++; 
	    } 

	    int i = result.length - 1; 
	    while (i >= 0 && result[i] == 0){ 
	        i--; 
        }
        
	    if (i == -1) 
	        return "0"; 

	String s = ""; 
	
	while (i >= 0) 
		s += (result[i--]); 

	return s; 
} 

   public static void main(String[] args) 
    { 
	Scanner sc=new Scanner(System.in);
       
        System.out.print("Enter the Number1: ");
        String str1=sc.nextLine();
        System.out.print("Enter the Number2: ");
        String str2=sc.nextLine();

	if ((str1.charAt(0) == '-' || str2.charAt(0) == '-') && 
		(str1.charAt(0) != '-' || str2.charAt(0) != '-')) 
		System.out.print("-"); 

	if (str1.charAt(0) == '-' && 
		str2.charAt(0) != '-') 
	{ 
		str1 = str1.substring(1); 
	} 
	else if (str1.charAt(0) != '-' && 
			str2.charAt(0) == '-') 
	{ 
		str2 = str2.substring(1); 
	} 
	else if (str1.charAt(0) == '-' && 
			str2.charAt(0) == '-') 
	{ 
		str1 = str1.substring(1); 
		str2 = str2.substring(1); 
	} 
	System.out.println(multiply(str1, str2)); 
} 
} 


