// https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately/0

#include <iostream>
using namespace std;

void rearrange(long long int arr[], int n){
    int max_index = n-1;
    int min_index = 0;
    int max = arr[n-1]+1;
    
    for(int i=0;i<n;i++){
        if(i%2==0){
            arr[i] = ( arr[max_index]%max ) * max + arr[i];
            max_index--;
        }else{
            arr[i] = ( arr[min_index]%max ) * max + arr[i];
            min_index++;
        }
    }
    
    for(int i=0;i<n;i++){
        arr[i]/=max; // arr[i] = arr[i]/max;
    }
}

int main() 
{
    int t;
    
    //testcases
    cin >> t;
    
    while(t--){
        
        //size of array
        int n;
        cin >> n;
        
        long long int arr[n];
        
        //adding elements to the array
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        //calling rearrange() function
        rearrange(arr, n);
        
        //printing the elements
        for (int i = 0; i < n; i++) 
		    cout << arr[i] << " ";
		
		cout << endl;
    }
	return 0; 
}
