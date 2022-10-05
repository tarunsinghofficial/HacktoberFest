#include<vector>
#include<iostream>
using namespace std;

bool isPartition(vector<int>& arr, int k, int mid){
    int studentNu = 1;
    int bookSum = 0;
    for(int i=0; i<arr.size(); i++){
        if(bookSum+arr[i]<= mid){
            bookSum += arr[i];
        }
        else{
            studentNu++;
            if(studentNu > k || arr[i] > mid){
                return false;
            }
            bookSum = arr[i];
        }
    }
    return true;
}

int bookAllocation(vector<int>& arr, int k){
    int s = 0;
    int sum = 0;
    for(int i=0; i<arr.size(); i++){
        sum += arr[i];
    }
    int e = sum;
    int mid = s+(e-s)/2;
    int ans = -1;
    while(s<=e){
        if(isPartition(arr,k,mid)){
            ans = mid;
            e = mid-1;
        }
        else{
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}

int main()
{
    
    return 0;
}
