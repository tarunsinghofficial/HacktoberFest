#include <iostream>
using namespace std;
int main()
{
    int a, b, gcd;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    for(int i = 1; i <= a && i <= b; ++i)
    {
        // Checks if i is factor of both integers
        if(a % i == 0 && b % i == 0)
            gcd = i;
    }
    cout << "G.C.D of " << a << " and " << b << " is " << gcd;
    return 0;
}