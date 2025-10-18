#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	//code
	int T;
	cin>>T;
	while(T--)
	{
	    int N, W;
	    cin>>N>>W;
	    vector<int> wt(N), v(N);
	    vector<vector<int>> wvt(N+1, vector<int>(W+1));
	    int i;

	    //int mx = INT_MIN;
	    for(i=0; i<N; i++)
	    {
	        cin>>v[i];

	    }
	    for(i=0; i<N; i++)
	    {
	        cin>>wt[i];
	    }

	    int w;

	   for (i = 0; i <= N; i++) {
         for (w = 0; w <= W; w++) {
             if (i == 0 || w == 0)
                 wvt[i][w] = 0;
             else if (wt[i - 1] <= w)
                 wvt[i][w] = max(
                     v[i - 1] + wvt[i - 1][w - wt[i - 1]],
                     wvt[i - 1][w]);
             else
                 wvt[i][w] = wvt[i - 1][w];
           }
       }
	   cout<<wvt[N][W]<<endl;
	   wt.clear();
	   v.clear();
	   wvt.clear();
	}
	return 0;
}
