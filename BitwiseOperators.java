public class bitwiseOperartors {
  

    public static void main(String[] args) {
          int number=323;
         System.out.println(checkEvenOROdd(number));
        System.out.println(findNoOfDigits(number, 10));
        System.out.println(checkSetBits(15));
    }
    static boolean checkEvenOROdd(int n)
    {
        return (n & 1)==1;
    }

    static int checkSetBits(int n)
    {   int count=0;
        while(n > 0)
        {
            if((n&1)==1)
            {
                count++;
                
            }
            n=n>>1; 
        }
        return count;
    }
    	static int MagicNumber(int n)
	{   int ans=0;
	    int base=5;
	  
	    while(n>0)
	    {
	        int last=n&1;
	        n=n>>1;
	        ans+=last*base;
	       base=base*5;
	    }
	   
	   return ans;
	}
    static int findNoOfDigits(int n,int base)
    {
        int ans=(int)(Math.log(n)/Math.log(base))+1;
        return ans;
    }
}
