#include<bits/stdc++.h>
using namespace std;

string addition(string str1, string str2)
{

	if (str1.length() > str2.length())
		swap(str1, str2);

	string str = "";

	int n1 = str1.length(), n2 = str2.length();

	reverse(str1.begin(), str1.end());
	reverse(str2.begin(), str2.end());

	int carry = 0;
	for (int i=0; i<n1; i++)
	{
		int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	for (int i=n1; i<n2; i++)
	{
		int sum = ((str2[i]-'0')+carry);
		str.push_back(sum%10 + '0');
		carry = sum/10;
	}

	if (carry)
		str.push_back(carry+'0');
		
	reverse(str.begin(), str.end());

	return str;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str1,str2;
        cin >>str1>>str2;
	    cout << addition(str1, str2)<<endl;
    }
	return 0;
}
