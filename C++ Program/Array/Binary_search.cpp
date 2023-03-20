//Binary Search
#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int key){
    int s=0;  //s=start
    int e=n;  //e=end
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid]==key){
        return mid;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }

    }
    return -1;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<binarySearch(arr,n,key)<<endl;
}
