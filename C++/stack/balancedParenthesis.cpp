#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool isValid(string s)
{
    bool ans;
    int n = s.length();
    stack<char> st;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == '}')
        {
            if ('{' == st.top() && !st.empty())
            {
                st.pop();
            }
            else
            {
                ans = false;
                return ans;
            }
        }
        else if (s[i] == ']')
        {
            if ('[' == st.top() && !st.empty())
            {
                st.pop();
            }
            else
            {
                ans = false;
                return ans;
            }
        }
        else if (s[i] == ')')
        {
            if ('(' == st.top() && !st.empty())
            {
                st.pop();
            }
            else
            {
                ans = false;
                return ans;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    return false;
}
main()
{
    string s = "{([{}])}";
    if (isValid(s))
    {
        cout << "Expression is Valid\n";
    }
    else
    {
        cout << "Expression is not Valid\n";
    }
}