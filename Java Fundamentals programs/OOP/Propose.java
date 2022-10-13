import java.util.Scanner;

public class Propose
{
    public static void main(String[] args)
    {
        try
        {
            Scanner input = new Scanner(System.in);
            System.out.println("Wanna propose to a girl? Enter your age:");
            int age = input.nextInt();

            if (age <= 16)
            {
                throw (new ILoveYouAsAFriendException());
            }
            else
            {
                System.out.println("Hooray! you win");
            }
        }
        catch (ILoveYouAsAFriendException e)
        {
            System.out.println(e.toString());
        }
    }
}