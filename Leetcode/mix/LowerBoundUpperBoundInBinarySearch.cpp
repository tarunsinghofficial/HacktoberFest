#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int upper_bound(vector<int> &arr,int ele){
    int low = 0, hi=arr.size() - 1;
    int mid;

    while (hi-low > 1)
    {
        mid = (hi-low)/2;

        if(arr[mid] <= ele){
            low = mid +1;
        }else{
            hi = mid;
        }
    }

    if(arr[low] > ele){
        return low;
    }
    
    if(arr[hi] > ele){
        return hi;
    }

    return -1;
}

int lower_bound(vector<int> &arr,int ele){
    int low = 0, hi=arr.size() - 1;
    int mid;

    while (hi-low > 1)
    {
        mid = (hi-low)/2;

        if(arr[mid] < ele){
            low = mid +1;
        }else{
            hi = mid;
        }
    }

    if(arr[low] >= ele){
        return low;
    }
    
    if(arr[hi] >= ele){
        return hi;
    }

    return -1;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);

    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    int element;
    cin>>element;

    cout<<lower_bound(v, element)<<endl;
    cout<<upper_bound(v, element)<<endl;
    
}





