import java.util.Scanner;

public class SetUpSite2
{
    public static void main(String[] args)
    {
        final int FOUNDED_YEAR = 1977;
        int currentYear;
        int age;

        Scanner input = new Scanner(System.in);
        System.out.println("Enter current year:");
        currentYear = input.nextInt();
        age = calculateAge(FOUNDED_YEAR, currentYear);
        System.out.println("Founded in " + FOUNDED_YEAR);
        System.out.println("Seving for " + age + " years");
    }

    public static void statementOfPhilosophy()
    {
        System.out.println("Event Handlers Inc. is");
        System.out.println("dedicated to making your event");
        System.out.println("a most memorable one.");
    }

    public static int calculateAge(int Org, int currYear)
    {
        int years;
        years = currYear - Org;
        return years;
    }
}