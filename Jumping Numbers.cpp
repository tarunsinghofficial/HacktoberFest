#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

set<long long> s;

void jumpingnums(long long d, long long N)
{
    if(d>N)
    {
        return;
    }
    if(d<=N)
    {
        s.insert(d);
    }
    long long mod = d%10;
    long long num;
	if(mod == 0)
	 {
	   num = d*10 + mod + 1;
	   jumpingnums(num, N);
	 }
	 else if(mod==9)
	  {
	    num = d*10 + mod - 1;
	    jumpingnums(num, N);
	  }
	 else
	 {
	     num = d*10 + mod - 1;
	     jumpingnums(num, N);
	     num = d*10 + mod + 1;
	     jumpingnums(num, N);
	 }

}


int main() {
	//code
	long long T, N, mod;
	long long i;
	cin>>T;
	while(T--)
	{
	    cin>>N;

	    for(i=1; i<=9; i++)
	    {
	       jumpingnums(i, N);

	    }

	    cout<<0<<" ";
	    for(auto itr = ::s.begin(); itr!=::s.end(); itr++)
	    {
	        cout<<(*itr)<<" ";
	    }
	    cout<<endl;
	    s.clear();
	}
	return 0;
}
