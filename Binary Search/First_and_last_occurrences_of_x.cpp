#include <bits/stdc++.h>
using namespace std;
int firstOccurence(int arr[], int n, int x)
{
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==x){
            ans = mid;
            end = mid-1;
        }
        else if(arr[mid]>x){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;

}
int LastOccurence(int arr[], int n, int x)
{
    int start = 0;
    int end = n-1;
    int ans = -1;
    while(start<=end){
        int mid = start+(end-start)/2;
        if(arr[mid]==x){
            ans = mid;
            start = mid+1;
        }
        else if(arr[mid]>x){
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    return ans;

}
vector<int> find(int arr[], int n, int x)
{
    // First Occurence
    vector<int> ans;
    ans.push_back(firstOccurence(arr,n,x));
    ans.push_back(LastOccurence(arr,n,x));
    return ans;
}
int main()
{
    int arr[] = {1, 3, 5, 5, 5, 5, 67, 123, 125};
    int x = 5;
    int n = 9;
    vector<int> ans = find(arr, n, x);

    return 0;
}