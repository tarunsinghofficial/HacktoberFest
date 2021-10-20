//Java my A$$

import java.util.Scanner;

public class BMI {
    public static void main(String[] args){

        Scanner input = new Scanner(System.in);

        System.out.println("BMI VALUES");
        System.out.println("Underweight: less than 18.5");
        System.out.println("Normal: between 18.5 and 24.9");
        System.out.println("Overweight: between 25 and 29.9");
        System.out.println("Obese: above 30\n");

        double weight, height;
        double BMI;
        System.out.println("Enter Your Weight:");
        weight=input.nextFloat();
        System.out.println("Enter Your Height:");
        height=input.nextFloat();
        BMI=weight/(height*height);

        System.out.println("BMI is: " + BMI);
    }
}