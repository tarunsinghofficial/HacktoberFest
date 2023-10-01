#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> books, int N, int M, int mid)
{
    int studentCount = 1;
    int pageSum = 0;
    for (int i = 0; i < N; i++)
    {
        if (pageSum + books[i] <= mid)
        {
            pageSum += books[i];
        }
        else
        {
            studentCount++;
            if (studentCount > M || books[i] > mid)
            {
                return false;
            }

            pageSum = books[i];
        }
        if (studentCount > M)
        {
            return false;
        }
    }
    return true;
}
int allocateBooks(vector<int> books, int N, int M)
{
    int start = 0;
    int end = 0;
    for (int i = 0; i < N; i++)
    {
        end = end + books[i];
    }
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (isPossible(books, N, M, mid))
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
