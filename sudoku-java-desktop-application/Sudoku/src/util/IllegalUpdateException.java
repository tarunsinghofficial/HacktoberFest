package util;
//An object of this class represents a failed update in a situation where the update was required
//to continue operations normally.
public final class IllegalUpdateException extends RuntimeException 
{
	private static final long serialVersionUID = 1L;
    public IllegalUpdateException(String mssg)
    {
    	super(mssg);
    }
}
