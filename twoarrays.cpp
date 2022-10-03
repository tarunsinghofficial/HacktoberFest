#include<iostream>
#include <algorithm>
using namespace std;

void operation(int array[], int size);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, p;
        cin >> n;
        int arr1[n], arr2[n];
        
        for (int i=0; i<n; i++){
            cin>>arr1[i];
        }
        for (int i=0; i<n; i++){
            cin>>arr2[i];
        }

        p=*max_element(arr1, arr1 + n) - *max_element(arr2, arr2 + n);

        for(int i=0; i<p; i++)
            operation(arr1, n);

        int sum=0; 

        for(int i=0; i<n; i++){
            if(arr1[i]==arr2[i]) sum++;
        }
        if(sum==n) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
   }
}

void operation(int array[], int size){
    
    for(int i=0; i<size; i++){
        if(array[i]!=0){
            array[i]--;    
        }
        else continue;
    }
    return;
}