import java.util.Scanner;

public class swapgeneric
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter Value 1");
        String value1 = input.next();
        System.out.println("Enter Value 2");
        String value2 = input.next();
        Swap(value1, value2);
    }

    public static <Dick> void Swap(Dick value1, Dick value2)
    {
        Dick temp = value1;
        value1 = value2;
        value2 = temp;

        System.out.println("Value 1: " + value1);
        System.out.println("Value 2: " + value2);
    }
}