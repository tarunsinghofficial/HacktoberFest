#include <bits/stdc++.h>
using namespace std;

inline float f(float x)
{
    return x*log10(x)-1.2;
}
inline float df(float x)
{
    return log10(x*exp(1));
}
int main()
{
    float a, e;
    int count=0;
    cout<<"Input a and error(e): ";
    cin>>a>>e;
    while(fabs(f(a))>=e and count++<100)
    {
        if (df(a)==0.f)
        {
            cerr<<"The tangent at "<< a <<" is parrallel to x-axis"<<endl;
            return 1;
        }
        a-=f(a)/df(a);
    }
    cout<<"The root of the equation is "<<a<<" with functional value "<<f(a)<<endl;
    return 0;
}
