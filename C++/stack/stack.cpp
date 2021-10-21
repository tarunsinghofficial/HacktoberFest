#include<iostream>
#include<vector>
using namespace std;
#define ll long long
class stack
{
    int* arr;
    int topp;

    public:
    stack(){
        arr=new int[10000];
        topp=-1;
    }

    void push(int val)
    {
        if(topp==9999)
        {
            cout<<"Stack overflow\n";
            return;
        }
        topp++;
        arr[topp]=val;
    }

    void pop()
    {
        if (topp<0)
        {
            cout<<"stack is empty\n";
            return;
        }
        
        topp--;
    }

    int top()
    {
        if(topp==-1)
        {
            cout<<"Stack empty\n";
            return -1;
        }
        return arr[topp];
    }

    bool empty()
    {
        if(topp==-1)
        {
            return true;
        }
        return false;
    }
};
main()
{
   stack st;
   st.push(1);
   st.push(2);
   st.push(3);
   st.push(4);
   st.push(5);
   st.push(6);
   cout<<st.top()<<endl;
}