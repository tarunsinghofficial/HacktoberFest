#include <iostream>
using namespace std;

long long fact(int n)
{
    if (n < 2)
        return 1;
    return n * fact(n - 1);
}

long long tailFact(int n, long long result = 1)
{
    if (n < 2)
        return result;
    return tailFact(n - 1, n * result);
}

int main()
{
    cout << "The factorial of  7 using non-tail recursion: " << fact(7) << endl;
    cout << "The factorial of  7 using tail recursion: " << tailFact(7) << endl;
    return 0;
}
