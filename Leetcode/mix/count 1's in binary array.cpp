// https://practice.geeksforgeeks.org/problems/count-1s-in-binary-array-1587115620/1



#include <bits/stdc++.h>
using namespace std;

// Function to count number of Ones
// arr: input array 
// N: size of input array
int countOnes(int arr[], int N)
{
    
    // Your code here
    int low=0;
    int high=N-1;
    
    while(low<=high){
        int mid = (low+high)/2;
        
        if(arr[mid]==0){
            high = mid-1;
        }
        else{
            if(arr[mid+1]==0 || mid==N-1){
                return mid+1;
            }else{
                low = mid+1;
            }
        }
        
         
    }
    
    return 0;
    
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        
        cout <<countOnes(arr, n)<<endl;
    }
    return 0;
}




/*



#include <bits/stdc++.h>
using namespace std;

// Function to count number of Ones
// arr: input array 
// N: size of input array
int countOnes(int arr[], int N)
{
    
    // Your code here
    int low= 0;
    int high = N-1;
    
    while(low<=high){
        int mid = (low+high) /2;
        
        if(arr[mid]==0){
            if(arr[mid-1]==1 || mid == 0){
                return mid;
            }else{
                high = mid-1;
            }
            
        }
        else{
            
            if(arr[mid+1]==0 || mid == N-1){
                return mid+1;
            }else{
                low = mid+1;
            }
        }
    }
    
    return 0;
    
}

int main()
{
    int t;
    cin>>t;
    
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        
        cout <<countOnes(arr, n)<<endl;
    }
    return 0;
}


*/
