import java.util.Random;

public class Rand
{
    public static void main(String[] args)
    {
        Random rnd = new Random();

        for (int i = 0; i <= 5; i++)
        {
            System.out.println(rnd.nextInt(10));
        }
    }
}