#include <bits/stdc++.h>
using namespace std;
// TIME COMPLEXITY OF O(log N)
int binarysearch(int arr[], int size, int key);
int main()
{
    cout << "Enter the size of the array" << endl;
    int n;
    cin >> n;
    cout << "Enter the elements in the array" << endl;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter the element you want to search" << endl;
    int key;
    cin >> key;
    sort(arr, arr + n);
    int ans = binarysearch(arr, n, key);
    cout << ans << endl;
    return 0;
}
int binarysearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size - 1;
    while (start <= end)
    {
        int middle = start + (end - start) / 2;
        if (arr[middle] < key)
        {
            start = middle + 1;
        }
        else if (arr[middle] > key)
        {
            end = middle - 1;
        }
        else
        {
            return middle;
        }
    }
    return -1;
}