#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=1e3+2;
vector<int> wt(N,0), v(N,0);


//function calculates the answer using recursion and dynamic programming(memoization)
int knapsack(int n, int w){
	vector<vector<int>> dp(N, vector<int>(N,-1));
	if(w<=0){
		return 0;
	}
	if(n<=0){
		return 0;
	}
	if(dp[n][w]!=-1){
		return dp[n][w];
	}
	if(wt[n-1]>w){
		dp[n][w] = knapsack(n-1, w);
	}
	else{
		dp[n][w] = max(knapsack(n-1, w), knapsack(n-1, w-wt[n-1]) + v[n-1] );
	}

	return dp[n][w];

}

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int n,w;
	    cin>>n>>w;
	    
		int i; 

	    //int mx = INT_MIN;
	    for(i=0; i<n; i++)
	    {
	        cin>>v[i];

	    }
	    for(i=0; i<n; i++)
	    {
	        cin>>wt[i];
	    }

		cout<<knapsack(n,w)<<endl; //calling the function

	   wt.clear();
	   v.clear();

	}
	return 0;
}
