#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> subsets;

void genrateSubset(vector<int> &subset, int i, vector<int> &nums)
{

    if (i == nums.size())
    {
        subsets.push_back(subset);
        return;
    }

    genrateSubset(subset, i + 1, nums);

    // i th element in subset
    subset.push_back(nums[i]);

    genrateSubset(subset, i + 1, nums);

    subset.pop_back();
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    vector<int> empty;

    genrateSubset(empty, 0, nums);

    for (auto subset : subsets)
    {
        for (auto ele : subset)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}
