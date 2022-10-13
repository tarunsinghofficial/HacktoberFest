import java.util.Scanner;

public class seperate{
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);
        int num, numCount=0;
        int div=1;
        int k;
       
        System.out.println("Enter Any Number:");
        num=input.nextInt();
        k=num;
        while (!(k<=0)){
            k/=10;
            numCount++;
        }

        for (int i=1;i<=numCount-1;i++){
            div*=10;
        }
        
       for (int x=0;x<numCount;x++){
           System.out.print(num/div + "     ");
            num%=div;
            div/=10; 
        }
    }
}