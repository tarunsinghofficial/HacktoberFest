#include<bits/stdc++.h>
using namespace std;
#define ll long long
int prefix(string s)
{
    stack<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            st.push(s[i]-'0');
        }
        else
        {
            int op1,op2;
            op2=st.top();
            st.pop();
            op1=st.top();
            st.pop();
            int ans;
            switch (s[i])
            {
                case '+':
                    ans=op1+op2;
                    break;
                case '-':
                    ans=op1-op2;
                    break;
                case '*':
                    ans=op1*op2;
                    break;
                case '/':
                    ans=op1/op2;
                    break;
                case '^':
                    ans=pow(op1,op2);
                    break;
            }
            st.push(ans);
        }
    }
    return st.top();
}
int main(int argc, char const *argv[])
{
    string s="46+2/5*7+";
    cout<<prefix(s)<<endl;
    return 0;
}
