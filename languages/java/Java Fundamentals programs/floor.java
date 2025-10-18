import java.util.Scanner;
public class floor{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        double num;
        
        System.out.println("Enter Any Decimal Number:");
        num=input.nextFloat();
        System.out.println("Enter Number of Decimal Places To Round Off:");
        System.out.println("The Rounded Value Is: " + Math.floor(100*num+0.5)/100);
    }
}