public class MultipleCheckException extends Exception
{
    public MultipleCheckException()
    {
        super("1st number cannot be a multiple of second number");
    }
}