#include <bits/stdc++.h>
using namespace std;
 
int sum(int arr[], int n)
{
    int sum = 0; // initialize sum

    for (int i = 0; i < n; i++)
    sum += arr[i];
 
    return sum;
}

int main()
{
    int arr[] = {12, 3, 4, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum of given array is " << sum(arr, n);
    return 0;

