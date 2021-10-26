#include<bits/stdc++.h>
using namespace std;
int main(){
    int a , b ;
    cin>>a>>b;
    int n1 = min(a,b);
    int n2 = max(a,b);
    
    while(n2%n1!=0){
        int temp = n2%n1 ;
        n2 = n1 ;
        n1 = temp ;
    }
    cout<<"GCD of two numbers is "<<n1<<endl;
    return 0;
}

/*
Euclid’s Algorithm: It is an efficient method for finding the GCD(Greatest  Common Divisor) of two integers. The time complexity of this algorithm is O(log(min(a, b)).

*/