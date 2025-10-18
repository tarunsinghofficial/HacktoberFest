public class Finalize
{
    public static void main(String[] args)
    {
        try
        {
            Finalize theshit = new Finalize();

            System.out.println("Before calling finalize() method");
            theshit.finalize();

            System.out.println("Before calling garbage collector");
            System.gc();
            System.out.println("garbage collected");
        }
        catch (Throwable e)
        {

        }
    }

    @Override
    protected void finalize() throws Throwable
    {
        System.out.println("Inside finalize() method");
    }
}