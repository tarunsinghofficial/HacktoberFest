public class fibonacci
{
	//using recursion
    static int fib(int x){// to remove static key word creating the object of the class and then use function with object
        if( x==1){
            return 1;
        }
        else if(x==0){
            return 0;
        }
        return fib(x-2)+fib(x-1);
    }
	public static void main(String[] args) {
	    int x = 5;
	    int a =0, b=1,sum=0;
	    for(int i=2;i<5;i++){ // using for loop
	        sum = a+b;//0+1->1+1->1+2->3
	        a = b;//1->1->2
	        b = sum;//1->2->3->
	    }
		x = fib(5);//Cannot make a static reference to the non-static method
		//fibonacci t = new fibonacci();// above problem can be solve by creating the object of the class
	    //x = t.fib(5);
		System.out.println(x);
	}
}

// 0 1 1 2 3 5