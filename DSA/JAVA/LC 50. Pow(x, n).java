class Solution {
    public double myPow(double x, int n) {
	// using recursion
        if(n==0) return 1.0;
        double ans = 0.0;
        double half = myPow(x,n/2);
        if(n%2==0)  ans = half*half;
        else if(n>0) ans = half*half*x;
        else if(n<0) ans = half*half/x;
        return ans;
    }
}



// Another approach using iterations instead
public double myPow(double x, int n) {
	double ans = 1.0;
	long N = n;
	if(n<0) N = -N;
	
	while(N>0) {
		if(N%2==1) {
	        	ans *= x;
	        	N--;
	        } else {	
			x *= x;
	        	N /= 2;
	        }
	}
	
	if(n<0) ans = 1.0 / ans;
	return ans;
}



// OPTIMAL
private long pow(long x, long n, int mod) {
        long res = 1;
        while (n > 0) {
            if (n % 2 == 1) res = (res * x) % mod;
            x = (x * x) % mod;
            n /= 2;
        }
        // System.out.println(res);
        return res;
    }