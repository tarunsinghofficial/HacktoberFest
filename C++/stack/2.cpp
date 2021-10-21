#include <bits/stdc++.h>
// #include<stack>
using namespace std;
void reversesentence(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        string word = "";
        while (s[i] != ' ' && i < s.size())
        {
            word = word + s[i];
            i++;
        }
        st.push(word);
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}
main()
{
    string s = "hey! how are you";
    reversesentence(s);
}