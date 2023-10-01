#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> boards, int k, int mid)
{
    int painterCnt = 1;
    int timeSum = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        if (timeSum + boards[i] <= mid)
        {
            timeSum += boards[i];
        }
        else
        {
            painterCnt++;
            if (painterCnt > k || boards[i] > mid)
            {
                return false;
            }
            timeSum = boards[i];
        }
        if (painterCnt > k)
        {
            return false;
        }
    }
    return true;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s = 0;
    int sum = 0;
    for (int i = 0; i < boards.size(); i++)
    {
        sum = sum + boards[i];
    }
    int e = sum;
    int ans = -1;
    while (s <= e)
    {
        int m = s + (e - s) / 2;
        if (isPossible(boards, k, m))
        {
            ans = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return ans;
}
int main()
{

    return 0;
}