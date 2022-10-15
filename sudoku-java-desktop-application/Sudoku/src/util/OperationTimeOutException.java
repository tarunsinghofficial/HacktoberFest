package util;
public final class OperationTimeOutException extends RuntimeException
{
	private static final long serialVersionUID = -7219213459299535718L;
    public OperationTimeOutException()
    {super();}
    public OperationTimeOutException(String s)
    {
    super(s);
    }
}
