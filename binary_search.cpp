/*
 * use binary search for the following goals:
 * looking for a target value 
 * the last/first element that satisfies some condition
 * real values
*/
#include <bits/stdc++.h>
using namespace std;
//simple binary search
int binary_search(vector<int>&v,int target){
	int n=v.size();
	int l=0,r=n-1;  
	while(l<=r)
	{
// expression of value of mid to be noted as (r+l)/2 can create overflow when dealing with bigger data types
		int mid=l+(r-l)/2;
		if(v[mid]>target)
		r=mid-1;
		else if(v[mid]<target)
		l=mid+1;
		else
		return mid;
	}
	return -1;
}
// square root using binary searching
int binsqrt(int target){
	int l=0,r=100;
	while(l<=r)
	{
		// expression of value of mid to be noted as (r+l)/2 can create overflow when dealing with bigger data types
		int mid=l+(r-l)/2;
		if(mid*mid>target)
		r=mid-1;
		else if(mid*mid<target)
		l=mid+1;
		else if(mid*mid==target)
		return mid;
	}
	return -1;
}
float precisebinsqrt(float target,float precision)
{
	float l = 0, r = target;
    while ((r-l)>precision) {
        float mid = l+(r-l)/2;
        if (mid * mid < target) {
            l = mid;
        }
        else 
            r = mid;
    }
    return l+(r-l)/2;
}

//first value greater than or equal to x
// task to find first true F F F T T T T at first T it satisfies >=x
int lowerbound(vector<int> &v,int x)
{
	int n=v.size();
	int l=0,r=n-1;
	int ans=-1;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(v[mid]>=x)
		{
			ans=mid;
			r=mid-1;
		}
		else
			l=mid+1;
	}
		 return ans;
}

//find the smallest element in a rotated array
// the initial array was in ascending order someone rotated it some x times now find the smallest
// element in the rotated array (any direction )
// 6 7 9 15 19 2 3
// T T T  T  T F F
// find the first F  
// ans[m] > ans[m-1]
// ans=m 
// l=m+1    

int main(){
	int n;
	cin >> n;
	//vector<int> v;
	for(int i=0;i<n;i++)
	{
		int x;
		//cin >> x;
		//v.push_back(x);
	}
	int s;
	//cin >> s;
	//cout << binary_search(v,s) << endl;
	//cout << binsqrt(n) << endl;
	cout << precisebinsqrt(n,0.00001) << endl;
}
		
		

