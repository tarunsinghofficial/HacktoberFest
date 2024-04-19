/*
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 
*/


#include<bits/stdc++.h>
using namespace std;

// Function to find majority element in the array
int majorityElement(int arr[], int n)
{
    int count=1; int res=0;
    for(int i=1; i<n; i++){
        if(arr[res] == arr[i])
            count++;
        else
            count--;
            
        if(count==0){
            count=1;
            res=i;
        }
    }
    
    //2nd   res 
    count=0;
    for(int i=0;i<n;i++){
        if(arr[res]==arr[i])
            count++;
    }
    
    if(count <= (n/2))
        return -1;
    else
        return arr[res];
}

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
