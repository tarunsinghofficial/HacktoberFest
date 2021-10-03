// https://practice.geeksforgeeks.org/problems/square-root/1



#include<bits/stdc++.h>
using namespace std;

long long int floorSqrt(long long int x);
  
  
// Function to find square root
// x: element to find square root
long long int floorSqrt(long long int x) 
{
    // Your code goes here
    int low = 1;
    int high = x;
    int ans = -1;
    
    while(low<=high){
        long long int mid = (low+high)/2;
        
        long long int sqr = mid*mid;
        
        if(sqr == x)
            return mid;
        else if(sqr < x){
            ans = mid;
            low = mid+1;
        }else{
            high = mid-1;
        }
    }
    
    return ans;
    
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		cout << floorSqrt(n) << endl;
	}
    return 0;   
}
