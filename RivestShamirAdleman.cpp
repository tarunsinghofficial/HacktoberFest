/*

Maitreya Kanitkar
BE-IT   8084

ICS Assignment 2 : RSA Algorithm

*/

#include<iostream>
using namespace std;

class rsa
{
    int p, q;
    double n, phi, e=2, g, d; 
    long msg, encrypted, decrypted, enc;
    
    public:
    void pipeline()
    {
        input();
        algorithm();
        output();
    }

    void input()
    {
        cout<<"Enter the value of p : ";
        cin>>p;

        cout<<"Enter the value of q : ";
        cin>>q;

        cout<<"Enter the message : ";
        cin>>msg;
    }

    int gcd(int a, int b)
    {
        if(a==0)
        return b;
        return gcd(b%a, a);
    }

    int mod(int m, int k, int n)
    {
        int result=1;

        m=m%n;

        if(m==0)
        return 0;

        while(k>0)
        {
            if(k%2==1)
            result=(result*m)%n;

            k/=2;
            m=(m*m)%n;
        }
        return result;
    }

    void algorithm()
    {
        n=p*q;
        phi=(p-1)*(q-1);

        while(e<phi)
        {
            if((gcd(e, phi)==1))
            break;
       
            else
            e++;
        }

        for(int i=1;i<phi;i++)
        if(((int)e*i)%(int)phi==1)
        d=i;

        encrypted=mod(msg, e, n);
        decrypted=mod(encrypted, d, n);
    }

    void output()
    {
        cout<<endl<<"Original message : "<<msg;
        cout<<endl<<"Encrypted message : "<<encrypted;
        cout<<endl<<"Decrypted message : "<<decrypted;
    }
};

int main()
{
    rsa obj;
    obj.pipeline();
    return 0;
}



/*

OUTPUT 1:-

Enter the value of p : 3
Enter the value of q : 7
Enter the message : 12

Original message : 12
Encrypted message : 3
Decrypted message : 12


OUTPUT 2:-

Enter the value of p : 91
Enter the value of q : 97
Enter the message : 1000

Original message : 1000
Encrypted message : 5095
Decrypted message : 1000

*/