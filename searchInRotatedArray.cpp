// Search in a rotated array
#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

int pivotIndex(vector<int>& arr, int n){
    int s=0,e=n-1;
    int mid;
    while(s<e){
        mid = s + (e - s)/2;
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }else{
            e=mid;
        }
    }
    return s;
}

int bs(vector<int>& arr, int s, int e, int key){
    int mid;
    while(s<=e){
        mid = s + (e - s) / 2;
        if(arr[mid]==key){
            return mid;
        }if(key>arr[mid]){
            s = mid + 1;
        }if(key<arr[mid]){
            e = mid - 1;
        }
    }
    return -1;
}

int search(vector<int>& arr, int n, int k)
{
    // Find the pivot index.
    int pivot = pivotIndex(arr, n);

    if (k >= arr[0] && k <= arr[pivot]) {
        // Search in the left subarray.
        return bs(arr, 0, pivot-1, k);
    } else {
        // Search in the right subarray.
        return bs(arr, pivot, n - 1, k);
    }
}


int main(){
    vector<int> arr = {4,5,6,1,2,8,11,12,45,58,90,100};
    int n = arr.size();
    cout<<"Key is present at index "<<search(arr,n,11)<<endl;
}