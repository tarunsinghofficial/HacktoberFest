//Author name:Prateek kannojia
//Question link:https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1

#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    vector<long long> NSL(long long arr[] , int n){
        vector<long long> ans;
        stack<pair<long long, int>> st; //element , index
        for(int i = 0 ; i < n ; i++){
            long long val = arr[i];
            while(!st.empty() && st.top().first >= val) st.pop();
            if(st.empty()) ans.push_back(-1);
            else ans.push_back(st.top().second);
            st.push({val , i});
        }
        return ans;
    }
    vector<long long> NSR(long long arr[] , int n){
        vector<long long> ans;
        stack<pair<long long,int>> st;;
        for(int i = n-1 ; i >= 0 ; i--){
            long long val = arr[i];
            while(!st.empty() && st.top().first >= val) st.pop();
            if(st.empty()) ans.push_back(n);
            else ans.push_back(st.top().second);
            st.push({val , i});
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
    long long MAH(long long arr[] , int n){
        vector<long long> sl = NSL(arr , n);
        vector<long long> sr = NSR(arr , n);
        vector<long long> ar;
        long long maxA = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            ar.push_back(sr[i]-sl[i]-1);
        }
        for(int i = 0 ; i < n ; i++){
            maxA = max(maxA , ar[i] * arr[i]);
        }
        return maxA;
    }
    long long getMaxArea(long long arr[], int n){
        return MAH(arr , n);
    }
};


int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
