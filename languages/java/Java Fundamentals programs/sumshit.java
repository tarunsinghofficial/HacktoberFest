public class sumshit
{
    public static void main(String args[])
    {
        int total = 0;

        for (int shit = 0; shit <= 20; shit++)
        {
            if (shit % 2 == 0)
            {
                total += shit;
            }
        }

        System.out.println("Total of all even numbers: " + total);
    }
}