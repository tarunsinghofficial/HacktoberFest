#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
	//code
	int T, t; //T is the no. of test cases
	cin>>T;
	long curr_sum, value;
	int i, start;
	int n, x, f=0; //n is no. of elements in the array
	vector<int> N; //N stores the input array
	for(t=0; t<T; t++) //loop for test cases
	{
	    cin>>n>>value;
	    for(i=0; i<n; i++)
	    {
	        cin>>x;
	        N.push_back(x);
	    }
	    start = 0;
	    curr_sum = N[0];
	    f=0;
	    for(i=1; i<=n; i++)
	    {
	        while(curr_sum > value && start <= i-1)
	        {
	            curr_sum -= N[start];
	            start++;
	        }
	        if(curr_sum == value)
	        {
	            cout<<start+1<<" "<<i<<endl;
	            f=1;
	            break;

	        }
	        if(curr_sum < value && i<n)
	        {
	            curr_sum += N[i];
	        }

	    }
	    if(f==0)
	    {
	        cout<<(-1)<<endl;
	    }

	    N.clear();
	}

	return 0;
}
