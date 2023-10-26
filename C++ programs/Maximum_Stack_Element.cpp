//Link :  https://www.hackerrank.com/challenges/maximum-element/problem

#include<bits/stdc++.h>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin>>N;
    stack<int> s, sm;
    int m = INT_MIN;

    while(N--)
    {
        int x, i;
        cin>>i;
        if(i==1)
        {
            cin>>x;
            s.push(x);
            m = max(m, x);
            sm.push(m);
        }
        else if(i == 2)
        {
            if(!s.empty())
            {
                s.pop();
                sm.pop();
                if(sm.empty())
                {
                    m = INT_MIN;
                }
                else
                {m = sm.top();}
            }
        }
        else if(i==3)
        {
            cout<<sm.top()<<endl;
        }
    }
    return 0;
}
