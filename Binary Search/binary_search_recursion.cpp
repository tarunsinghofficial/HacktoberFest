#include <iostream>
using namespace std;
bool binarySearch(int arr[], int n, int start, int end, int target)
{

    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == target)
    {
        return true;
    }
    else if (arr[mid] < target)
    {
        return binarySearch(arr, n, mid + 1, end, target);
    }
    else
    {
        return binarySearch(arr, n, start, mid - 1, target);
    }
}
int main()
{
    cout << "Enter the length of the array" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements in the array" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element to search" << endl;
    int target;
    cin >> target;
    bool ans = binarySearch(arr, n, 0, n - 1, target);
    if (ans)
    {
        cout << "Element Found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}