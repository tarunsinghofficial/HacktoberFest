#include <bits/stdc++.h>
using namespace std;
bool Compare(pair<int,int>p1,pair<int,int>p2)
{
    return p1.first<p2.first;
}
int main ()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    vector<pair<int,int>> v;
    for(i=0;i<n;++i)
    {
        v.push_back(make_pair(arr[i],i));
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();++i)
    {
        arr[v[i].second]=i;
    }
    for(i=0;i<v.size();++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}