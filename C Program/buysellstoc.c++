#include<bits/stdc++.h>

using namespace std;

int buystocks(vector<int>temp,int n){
    int maxpro=0;
    int minprice=INT_MAX;

    for(auto i:temp){
        minprice =min(minprice,i);
        maxpro=max(maxpro,(i-minprice));
    }
    return maxpro;
}


int main(){

    int n;
    cin>>n;

    vector<int> stocks;

    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        stocks.push_back(temp);
    }

    cout<<buystocks(stocks,n);


}