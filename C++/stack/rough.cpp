// // // // // // #include <bits/stdc++.h>
// // // // // // using namespace std;
// // // // // // #define n 100
// // // // // // class stacking
// // // // // // {
// // // // // //     int *arr;
// // // // // //     int top;

// // // // // // public:
// // // // // //     stacking()
// // // // // //     {
// // // // // //         arr = new int[n];
// // // // // //         top = -1;
// // // // // //     }

// // // // // //     void push(int ele)
// // // // // //     {
// // // // // //         if (top == n - 1)
// // // // // //         {
// // // // // //             cout << "data overflow\n";
// // // // // //             return;
// // // // // //         }

// // // // // //         top++;
// // // // // //         arr[top] = ele;
// // // // // //     }

// // // // // //     void pop()
// // // // // //     {
// // // // // //         if (top == -1)
// // // // // //         {
// // // // // //             cout << "The stack is empty\n";
// // // // // //         }
// // // // // //         top--;
// // // // // //     }

// // // // // //     bool empty()
// // // // // //     {
// // // // // //         if (top == -1)
// // // // // //         {
// // // // // //             return true;
// // // // // //         }
// // // // // //         else
// // // // // //         {
// // // // // //             return false;
// // // // // //         }
// // // // // //     }

// // // // // //     int Top()
// // // // // //     {
// // // // // //         if (top == -1)
// // // // // //         {
// // // // //             cout<<"Stack is empty\n";
// // // // // //             return -1;
// // // // // //         }
// // // // // //         return arr[top];
// // // // // //     }
// // // // // // };
// // // // // // main()
// // // // // // {
// // // // // //     stacking s;
// // // // // //     s.push(10);
// // // // // //     s.push(20);
// // // // // //     s.push(30);
// // // // // //     s.push(40);
// // // // // //     cout<<s.Top()<<endl;
// // // // // //     s.pop();
// // // // // //     cout<<bool(s.empty())<<endl;
// // // // // // }

// // // // // #include <bits/stdc++.h>
// // // // // #include <string>
// // // // // // #include<stack>
// // // // // using namespace std;
// // // // // void reversesentence(string s)
// // // // // {
// // // // //     stack<string> st;
// // // // //     for (int i = 0; i < s.size(); i++)
// // // // //     {
// // // // //         string word = "";
// // // // //         while (s[i] != ' ' && i < s.size())
// // // // //         {
// // // // //             word = word + s[i];
// // // // //             i++;
// // // // //         }
// // // // //         st.push(word);
// // // // //     }
// // // // //     while (!st.empty())
// // // // //     {
// // // // //         cout << st.top() << " ";
// // // // //         st.pop();
// // // // //     }
// // // // // }
// // // // // main()
// // // // // {
// // // // //     string s =" i am aradhya nice to see you";
// // // // //     reversesentence(s);
// // // // // }

// // // // #include<bits/stdc++.h>
// // // // using namespace std;
// // // // void insertattail(stack<int> &s,int ele)
// // // // {
// // // //     if(s.empty())
// // // //     {
// // // //         s.push(ele);
// // // //         return;
// // // //     }
// // // //     int topele=s.top();
// // // //     s.pop();
// // // //     insertattail(s,ele);
// // // //     s.push(topele);
// // // // }
// // // // void reverse(stack<int> &s)
// // // // {
// // // //     if(s.empty())
// // // //     {
// // // //         return;
// // // //     }
// // // //     int ele=s.top();
// // // //     s.pop();
// // // //     reverse(s);
// // // //     insertattail(s,ele);
// // // // }
// // // // main()
// // // // {
// // // //     stack<int> s;
// // // //     s.push(1);
// // // //     s.push(2);
// // // //     s.push(3);
// // // //     s.push(4);
// // // //     s.push(5);
// // // //     // reverse(s);
// // // //     while(!s.empty())
// // // //     {
// // // //         cout<<s.top()<<endl;
// // // //         s.pop();
// // // //     }
// // // // }

// // // #include <bits/stdc++.h>
// // // using namespace std;
// // // int prefixing(string s)
// // // {
// // //     stack<int> st;
// // //     for (int i = s.length() - 1; i >= 0; i--)
// // //     {
// // //         if (s[i] >= '0' && s[i] <= '9')
// // //         {
// // //             st.push(s[i] - '0');
// // //         }
// // //         else
// // //         {
// // //             int a = st.top();
// // //             st.pop();
// // //             int b = st.top();
// // //             st.pop();
// // //             switch (s[i])
// // //             {
// // //             case '+':
// // //                 st.push(a + b);
// // //                 break;
// // //             case '-':
// // //                 st.push(a - b);
// // //                 break;
// // //             case '*':
// // //                 st.push(a * b);
// // //                 break;
// // //             case '/':
// // //                 st.push(a / b);
// // //                 break;
// // //             case '^':
// // //                 st.push(pow(a, b));
// // //                 break;
// // //             default:
// // //                 cout<<"wrong input\n";
// // //                 break;
// // //             }
// // //         }
// // //     }
// // //     return st.top();
// // // }
// // // main()
// // // {
// // //     cout << prefixing("-+7*45+20") << endl;
// // // }

// // #include <bits/stdc++.h>
// // using namespace std;
// // int postfixing(string s)
// // {
// //     stack<int> st;
// //     for (int i = 0; i <= s.length() - 1; i++)
// //     {
// //         if (s[i] >= '0' && s[i] <= '9')
// //         {
// //             st.push(s[i] - '0');
// //         }
// //         else
// //         {
// //             int a = st.top();
// //             st.pop();
// //             int b = st.top();
// //             st.pop();
// //             switch (s[i])
// //             {
// //             case '+':
// //                 st.push(a + b);
// //                 break;
// //             case '-':
// //                 st.push(b - a);
// //                 break;
// //             case '*':
// //                 st.push(a * b);
// //                 break;
// //             case '/':
// //                 st.push(b / a);
// //                 break;
// //             case '^':
// //                 st.push(pow(b, a));
// //                 break;
// //             default:
// //                 cout << "wrong input\n";
// //                 break;
// //             }
// //         }
// //     }
// //     return st.top();
// // }
// // main()
// // {
// //     cout << postfixing("46+2/5*7+") << endl;
// // }

// #include <bits/stdc++.h>
// using namespace std;
// main()
// {
//     short t;
//     cin >> t;
//     while (t--)
//     {
//         long int x, r, m;
//         cin >> x >> r >> m;
//         m = m * 60;
//         r = r * 60;
//         long long int c = 0;
//         c+=min(x,r);
//         r-=min(x,r);
//         c+=r*2;
//         if (c <= m)
//         {
//             cout << "YES\n";
//         }
//         else
//         {
//             cout << "NO\n";
//         }
//     }
// }

// // #include<bits/stdc++.h>
// // using namespace std;
// // int precedence(char c)
// // {
// //     if(c=='^')
// //     {
// //         return 3;
// //     }
// //     else if(c=='*' || c=='/')
// //     {
// //         return 2;
// //     }
// //     else if(c=='+' || c=='-')
// //     {
// //         return 1;
// //     }
// //     else
// //     {
// //         return 0;
// //     }
// // }
// // void infixtopostfix(string s)
// // {   stack<int> st;
// //     string ss;
// //     for (int i = 0; i < s.length(); i++)
// //     {
// //         if((s[i]>='a' && s[i]<='z')||(s[i]>='A' && s[i]<'Z'))
// //         {
// //             ss=ss+s[i];
// //         }
// //         else if(s[i]=='(')
// //         {
// //             st.push(s[i]);
// //         }
// //         else if()
// //         {

// //         }
// //         else
// //         {

// //         }
// //     }
// // }
// // main()
// // {
// //     infixtopostfix("(a-b/c)*(a/k-l)");
// // }

#include <bits/stdc++.h>
using namespace std;
int precidence(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '-' || c == '+')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixtopostfix(string s)
{
    stack<int> st;
    string ss;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            ss = ss + s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ss += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precidence(st.top()) > precidence(s[i]))
            {
                ss += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty())
    {
        ss+=st.top();
        st.pop();
    }
    return ss;
}
main()
{
    string s = "(a-b/c)*(a/k-l)";
    cout << infixtopostfix(s) << endl;
}