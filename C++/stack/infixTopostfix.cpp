#include <bits/stdc++.h>
using namespace std;
#define ll long long
int prec(char c)
{
    if (c == '^'){
        
        return 3;
    }
    else if (c == '*' || c == '/'){
        
        return 2;
    }
    else if (c == '+' || c == '-'){
        return 1;
    }
    else{
        
        return -1;
    }
}
string infixTopostfix(string s)
{
    stack<char> st;
    string rev="";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            rev+=s[i];
        }
        else if (s[i] == '(')
        {
            st.push('(');
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                rev+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top())>prec(s[i]))
            {
                rev+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        rev+=st.top();
        st.pop();
    }
    return rev;
}
main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout<<infixTopostfix(s)<<endl;;
}