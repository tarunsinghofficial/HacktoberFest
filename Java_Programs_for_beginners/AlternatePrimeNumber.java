    import java.util.*;  
    public class AlternatePrimeNumber  
    {  
    public static void main(String args[])  
    {  
    int n;  
    int status = 1;  
    int num = 3;  
    //object of the ArrayList class  
    List<Integer> primelist=new ArrayList<Integer>();  
    //object of the Scanner class  
    Scanner scanner = new Scanner(System.in);  
    System.out.print("Enter the value of n: ");  
    //reading the value of n from the user  
    n = scanner.nextInt();  
    if (n >= 1)  
    {  
    System.out.println("First "+n+" prime numbers are: ");  
    //2 is a known prime number  
    System.out.println(2);  
    //adding 2 in the ArrayList  
    primelist.add(2);  
    }  
    for(int i = 2 ; i <=n ; )  
    {  
    for(int j = 2 ; j <= Math.sqrt(num) ; j++)  
    {  
    if(num%j == 0)  
    {  
    status = 0;  
    break;  
    }  
    }  
    if(status != 0)  
    {  
    System.out.println(num);  
    //adding numbers to the ArrayList  
    primelist.add(num);  
    i++;  
    }  
    status = 1;  
    num++;  
    }  
    System.out.println("Alternate prime numbers are:");  
    //loop for printing the alternate prime numbers  
    for(int k=0;k<primelist.size();k++)  
    {  
    if((k%2)==0)  
    System.out.println(""+primelist.get(k));  
    }  
    }  
    }  
