package Basic_Java_Project;

import java.util.Scanner;

public class CurrencyConverter {
     public static void convert(int n,String Currency) {
        switch (Currency) {
            case "dollar": System.out.println(n+" isEqual to " +(n*0.012251)+"USD");
            break;

            case "pkr" : System.out.println(n+" isEqual to " +(n*2.72)+"PKR");
            break;

            case "euro" : System.out.println(n+" isEqual to " +(n*0.012)+"Euro");
            break;

            case "pound" : System.out.println(n+" isEqual to " +(n*0.010)+"Pound");
            break;

            case "aed" : System.out.println(n+" isEqual to " +(n*0.045)+"AED");
            break;

            case "yuan" : System.out.println(n+" isEqual to " +(n*0.087)+"Yuan");
            break;

            case "yen" : System.out.println(n+" isEqual to " +(n*1.7)+"Yen");
            break;   
        
            default:
            System.out.println("Currency not available");
                break;
        }
    }
    public static void main(String[] args) {
        Scanner s=new Scanner(System.in);
        System.out.println("Hello!! Here You can Convert Indian currency to dollar, pkr, euro, pound, aed, yuan, yen");
        System.out.println();
        System.out.println("Enter Currency in inr");
        int n=s.nextInt();
        System.out.println("Enter Currency in which you want to Convert to ");
        String currency=s.next();
        convert(n, currency);
        s.close();

    }
}
