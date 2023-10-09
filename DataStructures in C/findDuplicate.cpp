#include <iostream>
using namespace std;
void findDuplicate(int arr[] , int size){
    int counter=0 , dup[100];
    for(int i=0; i<size; i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]==arr[j]){
                dup[counter] = arr[i];
                counter++;
            }
        }
    }

    // for(int i=0; i<counter; i++){
    //     for(int j=i+1; j<counter; j++){
    //         if(dup[i]==dup[j]){
    //             for(int k=j;k<counter;k++){
    //                 dup[k] = dup[k+1];
    //             }
    //             counter--;
    //         } 
    //     }
    // }

    for(int i=0; i<counter; i++){
        for(int j=i+1; j<counter;j++){
            if(dup[i]==dup[j]){
                for(int k=j; k<counter/2; k++){
                    dup[k] = dup[k+1]; 
                } 
                counter--;
            }
        }
    }

    for(int i=0; i<counter; i++){
        cout<<dup[i]<<endl;
    }
  
}

int main(){
    int arr[100];
    int size;
    cout<<"Enter size of array :"<<endl;
    cin>>size;
    
    for(int i=0; i<size; i++){
       cout<<"Enter arr["<<i<<"] element: "<<endl;
       cin>>arr[i];
    }
    
    for(int i=0; i<size; i++){
        cout<<arr[i]<<endl;
    }

    cout<<"The duplicate elements are : "<<endl; 
    findDuplicate(arr,size);

}  