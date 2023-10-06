

import java.util.Scanner;

public class GradeCalculator{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the marks obtained in Painting out of 100: ");
        int painting = sc.nextInt();
        System.out.print("Enter the marks obtained in English out of 100: ");
        int english = sc.nextInt();
        System.out.print("Enter the marks obtained in Math out of 100: ");
        int math = sc.nextInt();
        System.out.print("Enter the marks obtained in Physics out of 100: ");
        int physics = sc.nextInt();
        System.out.print("Enter the marks obtained in Chemistry out of 100: ");
        int chemistry = sc.nextInt();

        int averagePercentage = ((painting + english + math + physics + chemistry)/5);
        int totalMarks = painting + english + math + physics + chemistry;


        System.out.println("\nOutstanding for 100 to 90 marks. ");
        System.out.println("Excellent for 89 to 80 marks. ");
        System.out.println("Very Good for 79 to 70 marks. ");
        System.out.println("Good for 69 to 60 marks. ");
        System.out.println("Fair for 59 to 50 marks. ");
        System.out.println("Below Average for 49 to 40 marks. ");
        System.out.println("Fail for below 40. ");

        System.out.println("\nYour total marks is: "+totalMarks);

        System.out.println("\nYour Average percentage is : "+averagePercentage);

        System.out.println("\nGrade acoorrding to your marks is given below: ");

        if(averagePercentage<=100 && averagePercentage>=90){
            System.out.print("OUTSTANDING.");
        }

        else if(averagePercentage<=89 && averagePercentage>=80){
            System.out.print("EXCELLENT.");
        }

        else if(averagePercentage<=79 && averagePercentage>=70){
            System.out.print("VERY GOOD.");
        }

        else if(averagePercentage<=69 && averagePercentage>=60){
            System.out.print("GOOD.");
        }

        else if(averagePercentage<=59 && averagePercentage>=50){
            System.out.print("FAIR.");
        }

        else if(averagePercentage<=49 && averagePercentage>=40){
            System.out.print("BELOW AVERAGE.");
        }

        else if(averagePercentage<40){
            System.out.print("FAIL.");
        }

        sc.close();

        
    }
}