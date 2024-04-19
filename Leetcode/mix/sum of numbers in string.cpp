// https://practice.geeksforgeeks.org/problems/sum-of-numbers-in-string/0

#include <iostream>
using namespace std;

int findSum(string s)
{
	// Your code here
	int n = (int)s.size();
	int num=0;
	int sum=0;
	for(int i=0;i<n;i++){
	    
	    if(s[i]>='0' && s[i]<='9')
	        num = num*10 + (s[i]-'0');
	    else{
	        sum += num;
	        num = 0;
	    }
	}
	
	return sum+num;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    cout << findSum(str);
        cout<<endl;
	}
	return 0;
}
