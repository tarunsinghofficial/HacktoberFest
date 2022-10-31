import java.util.Scanner;

 class FactorOfANumber{
     public static void main(String[] args) {
         System.out.println("Enter the number to find the factor:");
         Scanner in = new Scanner(System.in);
         int num = in.nextInt();
     System.out.println("The factors of "+num +" are : " );
         for(int i = 1; i<=num; i++){
             if(num%i == 0){
 System.out.print(i+" ");
           }
         }
         in.close();
}
}
