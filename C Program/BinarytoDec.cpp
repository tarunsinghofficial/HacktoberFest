#include <iostream>
using namespace std;

int bintodec(int n)
{
    int lastdig, x = 1, dec_num = 0;
    while (n > 0)
    {
        lastdig = n % 10;
        dec_num = dec_num + x * lastdig;
        x = x * 2;
        n = n / 10;
    }
    return dec_num;
}

int main()
{
    int dec, n;
    cin >> n;
    dec = bintodec(n);
    cout << dec;
    return 0;
}