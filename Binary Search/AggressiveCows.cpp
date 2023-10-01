#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> stalls, int k, int m)
{
    int cowCnt = 1;
    int lastPos = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= m)
        {
            cowCnt++;
            if (cowCnt == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int e = stalls[stalls.size() - 1] - stalls[0];
    int ans = -1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (isPossible(stalls, k, m))
        {
            ans = m;
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    return ans;
}
int main()
{

    return 0;
}