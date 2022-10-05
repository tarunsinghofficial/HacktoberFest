import java.util.Scanner;
import java.lang.Math;
class javaprog {
    public static void main(String[] args){
        System.out.println("1. print factorial of n number ");
        System.out.println("2. print sum of n natural number ");
        System.out.println("3. print if a number is palindrome or not  ");
        System.out.println("4. print the number of digits in a number  ");
        System.out.println("5. print star pattern  ");
        System.out.println("6. enter your choice from m to n");
        System.out.println("Enter choice from 1 - 6 to perform operation: ");
        Scanner obj = new Scanner(System.in);
        int choice = obj.nextInt();
 
        switch (choice){
            case 1:
            	fact();
                break;
            case 2:
                sum();
                break;
            case 3:
                armstrong();
                break;
            case 4:
                digits();
                break;
            case 5:
                pattern();
                break;
            case 6:
                even();
                break;
            default:
                System.out.println("Read the instruction carefully!");
        }
 
 
 
 
    }
 
    public static void fact() {
        System.out.println("Enter a number: ");
 
        Scanner input =  new Scanner(System.in);
        int num = input.nextInt();
        System.out.println("The factorial of "+ num+ " is : " + recuFact(num));
 
    }
 
    public static int recuFact(int n){
		if(n==1){
			return 1;
		}
		return n*recuFact(n-1);
		}
 
 
    public static void sum() {
        System.out.println("Enter a number: ");
        Scanner input =  new Scanner(System.in);
        int num = input.nextInt();
        int sum = 0;
        for(int i = 1;i<=num;i++){
            sum+=i;
        }
        System.out.println("The sum of first "+num+" natural number is : " + sum);
 
    }
    public static void armstrong() {
        System.out.println("Enter a number: ");
        Scanner input =  new Scanner(System.in);
        int num = input.nextInt();
        int calcNum = num;
        int remainder;
        int sum = 0;
        while(calcNum !=0){
            remainder = calcNum % 10;
            sum+=Math.pow(remainder,3);
            calcNum = calcNum / 10;
        }
 
        String res = (sum==num) ? num + " is a Armstrong number" : num + " is not a Armstrong number";
        System.out.println(res);
    }
    public static void digits() {
        System.out.println("Enter a number: ");
        Scanner input =  new Scanner(System.in);
        int num = input.nextInt();
        int calcNum = num;
        int remainder;
        int sum = 0;
        while(calcNum !=0){
            remainder = calcNum % 10;
            sum+=1;
            calcNum = calcNum / 10;
        }
        System.out.println("The no. digits in "+ num +  " is " + sum);
    }
 
    public static void pattern() {
        int n = 5;
        for(int i = 1;i<=n;i++){
			int space = n-i;
			int innerspace = i-1;
			for(int j=1;j<=space;j++){
				System.out.print("   ");
			}
			for(int k=1;k<=i;k++){
				System.out.print(" * ");
				if(innerspace!=0){
					System.out.print("   ");
					innerspace--;
				}
			}
			for(int j=1;j<=space;j++){
				System.out.print(" ");
			}
			System.out.println("\n");
 
		}
 
 
 
 
    }
    public static void even(){
        Scanner input =  new Scanner(System.in);
 
        System.out.println("Enter a number m: ");
        int m = input.nextInt();
        System.out.println("Enter a number n: ");
        int n = input.nextInt();
 
        int even_numbers = 0;
        for (int i = m+1 ;i<n;i++){
            if(i%2==0){
				even_numbers++;
			}
        }
        System.out.println(even_numbers + " even numbers are there between "+m+" and "+n);
 
 
    }
 
 
}
