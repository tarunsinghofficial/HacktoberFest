#include<bits/stdc++.h>
using namespace std;
#define n 100
class stacking{
    int* arr;
    int top;
    public:
    stacking(){
        arr=new int[n];
        top=-1;
    }
    void push(int x){
        if(top==n-1){
            cout<<"Stack overflow"<<endl;
            return;
        }
        top++;
        arr[top]=x;
    }
    void pop(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
            return;
        }
        top--;
    }
    int Top(){
        if(top==-1){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
    bool empty(){
        return top==-1;
    }
};
int main(){
    stacking st;
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.Top()<<endl;
    st.pop();
    cout<<st.empty()<<endl;
    st.pop();
    cout<<st.empty()<<endl;
    return 0;
}