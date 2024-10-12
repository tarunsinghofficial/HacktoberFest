#include <iostream>
#include <string>
using namespace std;

int main() {
	//code
	string s;
	int T, i, j;
	cin>>T;
	int maxl, left, right, leftj, rightj ;
	while(T--)
	{
	    cin>>s;
	    maxl = 0;
	    left = 0;
	    right = 0;
	    leftj = 0;
	    rightj = 0;

	    for(i=0, j=s.size()-1; i<s.size(), j>=0; i++, j--)
	    {
	        if(s[i]=='(')
	        {
	            left++;
	        }
	        else
	        {
	            right++;
	        }
	        if(left==right)
	        {
	            maxl = max(maxl, 2*left);
	        }
	        else if(right>left)
	        {
	            right = 0;
	            left = 0;
	        }
	         if(s[j]=='(')
	        {
	            leftj++;
	        }
	        else
	        {
	            rightj++;
	        }
	        if(leftj==rightj)
	        {
	            maxl = max(maxl, 2*leftj);
	        }
	        else if(rightj<leftj)
	        {
	            rightj = 0;
	            leftj = 0;
	        }

	    }

	    cout<<maxl<<endl;
	    s.clear();
	}
	return 0;
}
