public class ExceptionThrows {
    public static int testExceptionDivide(int a, int b) throws ArithmeticException{
        if(a == 0 || b == 0)
            throw new ArithmeticException();
        return a/b;
    }
    public static void main(String args[]) {
        try{
            int val = testExceptionDivide(10, 1);
            System.out.println(val);
        }
        catch(ArithmeticException e){
            //Handle the exception
        }
    }
}

//The ‘throw’ keyword is used to manually throw the exception to the calling method.
//And the ‘throws’ keyword is used in the function definition to inform the calling method that this method throws the exception. 
//So if you are calling, then you have to handle the exception.
