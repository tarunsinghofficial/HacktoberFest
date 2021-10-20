import java.util.Scanner;

public class TheCode
{
    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);

        try
        {
            int num1 = input.nextInt();
            int num2 = input.nextInt();
           
            System.out.println(ZeroCheck(num2));
            System.out.println(MultipleCheck(num1, num2));
            System.out.println(NegCheck(num1, num2));
            System.out.println(SmallCheck(num1, num2));
        }
        catch (MultipleCheckException e)
        {
            System.out.println(e);
        }
        catch (NegativeException e)
        {
            System.out.println(e);
        }
        catch (SmallException e)
        {
            System.out.println(e);
        }
        catch (ZeroException e)
        {
            System.out.println(e);
        }
    }

    public static String MultipleCheck(int a, int b) throws MultipleCheckException
    {
        if (a % b == 0)
        {
            throw (new MultipleCheckException());
        }
        return "Multiple Check: All is well!";
    }

    public static String NegCheck(int a, int b) throws NegativeException
    {
        if (a < 0 || b < 0)
        {
            throw (new NegativeException());
        }
        return "Negative Check: All is well!";
    }

    public static String SmallCheck(int a, int b) throws SmallException
    {
        if (a < b)
        {
            throw (new SmallException());
        }
        return "Small Check: All is well!";
    }

    public static String ZeroCheck(int b) throws ZeroException
    {
        if (b == 0)
        {
            throw (new ZeroException());
        }
        return "Zero Check: All is well";
    }
}
