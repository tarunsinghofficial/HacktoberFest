#include <bits/stdc++.h>
using namespace std;
int mySqrt(int x)
{
    if (x == 0 || x == 1)
    {
        return x;
    }
    int ans = -1;
    int start = 0;
    int end = x - 1;
    while (start <= end)
    {
        long long int mid = start + (end - start) / 2;
        if (mid * mid > x)
        {
            end = mid - 1;
        }
        else if (mid * mid < x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return ans;
}
int main()
{

    return 0;
}