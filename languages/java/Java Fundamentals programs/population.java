import java.util.Scanner;

public class population{
    public static void main(String[] args) {
        
        Scanner input = new Scanner(System.in);

        int pop, years;
        float rate;
       double finalPop;

        System.out.println("Enter the current population in your country:");
        pop=input.nextInt();
        System.out.println("Enter the growth rate (per year):");
        rate=input.nextFloat();
        System.out.println("Enter the years you want to find the population change:");
        years = input.nextInt();

        System.out.println(pop + " " + rate + " " + years);
        finalPop=(pop + (pop*rate/100)*years);
        System.out.println("Population after: " + years + " years will be: " + finalPop);

    }
}