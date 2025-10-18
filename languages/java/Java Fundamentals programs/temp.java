import java.util.Scanner;

public class temp{
    public static void main(String[] args) {
        Scanner input =new Scanner(System.in);
        double celsius, fahr, conversion=0;
        int choice;

        System.out.println("SELECT ONE OPTION FROM BELOW:");
        System.out.println("1. Convert Celsius to Fahrenheit.\n2. Convert Fahrenheit to Celsius.");
        choice=input.nextInt();

        switch(choice){
        
            case 1:
            System.out.println("Enter The Celsius Temperature:");
            celsius=input.nextDouble();
            fahr= 9.0 / 5.0 * celsius + 32;
            conversion=fahr;
            break;
        
            case 2:
            System.out.println("Enter The Fahrenheit Temperature:");
            fahr=input.nextDouble();
            celsius = 5.0 / 9.0 * fahr - 32;
            conversion=celsius;
            break;

            default:
            System.out.print("Enter A Valid Choice!");
            break;
        }

        System.out.println("The Converted Value Is: " + conversion);
    }
}