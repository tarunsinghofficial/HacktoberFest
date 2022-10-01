#include<bits/stdc++.h>

using namespace std;

int main(){

    vector<int> permu;
    int n;
    cout<<"enter the numbers";
    cin>>n;

    int x=0;
    int i=0,j=0;
    for(int i=0;i<n;i++){
        cin>>x;
        permu.push_back(x);
    }

    for(i=permu.size()-2;i>=0;i--){

        if(permu[i] < permu[i+1]){
            break;
        }
    }

    if(i<0){
        reverse(permu.begin(),permu.end());
    }else{
    for(j=permu.size()-1 ; j>i ; j--){
        if(permu[j]>permu[i]){
            break;
        }

    }
    

    swap(permu[j],permu[i]);
    sort(permu.begin()+i+1,permu.end());
    }

    
    for(int i=0;i<permu.size();i++){
        cout<<permu[i]<<" ";
    }


return 0;
}