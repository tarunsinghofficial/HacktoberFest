#include<bits/stdc++.h>
using namespace std;
#define ll long long

int prec(char c)
{
    if(c=='^')
    {
        return 3;
    }
    else if(c=='*' || c=='/')
    {
        return 2;
    }
    else if(c=='+' || c=='-')
    {
        return 1;
    }
    else{
        return -1;
    }
}

string reverse(string s)
{
    string ss="";
    for (int i = s.length(); i >= 0; i--)
    {
        ss=ss+s[i];
    }
    return ss;
}

string bracket(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='(')
        {
            s[i]=')';
        }
        else if(s[i]==')')
        {
            s[i]='(';
        }
    }
    return s;
}

string infixToPrefix(string s)
{
    s=reverse(s);
    s=bracket(s);
    string ans="";
    stack<char> st;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>='a' && s[i]<='z')
        {
            ans+=s[i];
        }
        else if(s[i]=='(')
        {
            st.push(s[i]);
        }
        else if(s[i]==')')
        {
            while (!st.empty() && st.top()!='(')
            {
                ans+=st.top();
                st.pop();
            }
            if(!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            if(!st.empty() && prec(st.top())>prec(s[i]))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    ans=reverse(ans);
    // ans=bracket(ans);
    return ans;
}

main()
{
   string s="(a-b/c)*(a/k-l)";
   cout<<infixToPrefix(s)<<endl;
}