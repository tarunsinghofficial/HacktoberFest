#include <iostream>
#include <cmath>
using namespace std;

inline float f(const float& x)
{
    return log10(x) - 2*x + 6;
}

int main()
{
    float a, b, e;
    cout<<"Input a, b and e: ";
    cin>>a>>b>>e;
    int maxIter;
    if (b>a)
        maxIter = 2*log((b-a)/e)/log(2.f);
    else
    {
        cerr<<"Input range in proper order"<<endl;
        return 1;
    }
    if(f(a)*f(b)==0)
    {
        if(f(a)==0)
            cout<<a<<" is a root of the equation."<<endl;
        if(f(b)==0)
            cout<<b<<" is a root of the equation."<<endl;
    }
    else if (f(a)*f(b)>0)
        cout<<"The root doesn't lie in between the interval"<<endl;
    else
    {
        float c;
        int count=0;
        do
        {
            count++;
            c=(a+b)/2;
            if(f(a)*f(c)<0)
                b=c;
            else    
                a=c;
        }while(fabs(f(c))>=e and count<=maxIter);
        cout<<"The root of equation is "<<c<<" with functional value "<<f(c)<< " with count "<<count<<endl;
    }
    return 0;
}
