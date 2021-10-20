public class NegativeException extends Exception
{
    public NegativeException()
    {
        super("Either number should not be negative");
    }
}