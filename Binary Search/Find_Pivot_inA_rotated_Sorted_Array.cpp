#include <bits/stdc++.h>
using namespace std;
int findPivot(vector<int> &arr){
    int start = 0;
    int end = arr.size()-1;
    while(start<end){
        int mid = start + (end-start)/2;
        if(arr[mid]>=arr[0]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }
    return start;
}
int main()
{
    vector<int> arr;

    return 0;
}