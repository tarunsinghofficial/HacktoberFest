#include <bits/stdc++.h>
using namespace std;
int findPivot(vector<int> &arr)
{
    int start = 0;
    int end = arr.size() - 1;
    while (start < end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= arr[0])
        {
            start = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return start;
}
int binarySearch(vector<int> &arr, int target, int start, int end)
{

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}
int search(vector<int> &nums, int target)
{
    int pivot = findPivot(nums);
    if (target >= nums[pivot] && target <= nums[nums.size() - 1])
    {
        return binarySearch(nums, target, pivot, nums.size() - 1);
    }
    else
    {
        return binarySearch(nums, target, 0, pivot - 1);
    }
}
int main()
{

    return 0;
}