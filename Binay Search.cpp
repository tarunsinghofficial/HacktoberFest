 #include<bits/stdc++.h>
 using namespace std;
 
 
int binarySearch(vector<int>&array, int x, int low, int high) 
{
 
    while (low <= high)
    {
       int mid = low + (high - low) / 2;
  
      if (array[mid] == x)
        return mid;

       if (array[mid] < x)
         low = mid + 1;

       else
         high = mid - 1;
    }

     return -1;
}
 
 
 int main()
 {
    int n,key;
    
    vector<int>nums(n);
    cin>>n>>key;
    
    for(int i=0;i<n;i++)
    cin>>nums[i];

    int ans=binarySearch(nums,key,0,n-1);
    if(ans==-1)
    cout<<"Element not found"<<endl;
    else
    cout<<"Element is found at index "<<ans;

  return 0;



 }
