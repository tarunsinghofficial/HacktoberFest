/*

Maitreya Kanitkar
BE-IT   8084

ICS Assignment 1 : CRT Algorithm

*/

#include<iostream>
#include<vector>
using namespace std;

class crt
{
    vector<int>bi, ni, Ni, yi;
    int n, N=1, x=0;

    public:
    
    int pipeline()
    {
        input();
        if(relativePrime()==0)
        return 0;
        calcNi();
        inverse();
        return output();
    }

    void input()
    {
        int r, d;

        cout<<"Enter the number of divisiors or remainders : ";
        cin>>n;

        cout<<endl<<"Enter the divisors and the corresponding remainders : "<<endl;
	    for(int i=0; i<n; i++)
        {
		    cin>>d>>r;
		    ni.push_back(d);
            bi.push_back(r);	
	    }
    }

    int gcd(int num1, int num2)
    {
        if (num2==0)
        return num1;
        return gcd(num2, num1%num2);
    }

    int relativePrime()
    {
        for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
		if(gcd(ni.at(i), ni.at(j))!=1)
		return 0;	
	    return 1;
    }

    void calcNi()
    {
        for(int i=0;i<n;i++)
        N*=ni.at(i);
        
        for(int i=0;i<n;i++)
        Ni.push_back(N/ni.at(i));
    }

    void inverse()
    {
        for(int i=0;i<n;i++)
		for(int j=1;j<ni.at(i);j++)
		if((Ni[i]*j)%ni[i]==1)
        {
			yi.push_back(j);
			break;
		}
    }

    int output()
    {
        for(int i=0;i<n;i++)
        x+=bi.at(i)*Ni.at(i)*yi.at(i);
        return x%N;
    }
};

int main()
{
    int solution;
    crt obj;

    solution=obj.pipeline();

    if(solution==0)
    cout<<"Solution not possible as divisors aren't relatively prime.";
    else
    cout<<endl<<"X="<<solution;

    return 0;
}


/*

OUTPUT 1:

Enter the number of divisiors or remainders : 3

Enter the divisors and the corresponding remainders :
3 2
4 3
5 1

X=11


OUTPUT 2:

Enter the number of divisiors or remainders : 3

Enter the divisors and the corresponding remainders :
3 2
3 4
5 1
Solution not possible as divisors aren't relatively prime.

*/