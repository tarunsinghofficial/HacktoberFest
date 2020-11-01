import java.io.*;
class FactorialRecursion
{
    int factorial(int n)
    {
        if(n==0||n==1)
        return n;
        else
        return n*factorial(n-1);
    }
    public static void main(String args[]) throws IOException
    {
        int n;
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Enter an integer to find its factorial: ");
        n=Integer.parseInt(br.readLine());
        FactorialRecursion ob=new FactorialRecursion();
        System.out.println("The factorial of "+n+" is "+ob.factorial(n)+".");
    }
}