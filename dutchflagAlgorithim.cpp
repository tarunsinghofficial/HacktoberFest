#include<bits/stdc++.h>    
using namespace std;    
   
void JTP(int arr[], int arr_size)    
{   
int low = 0;    
int high = arr_size - 1;    
int mid = 0;    
   
while (mid <= high)    
{    
switch (arr[mid])    
{    
// Here mid is 0.    
case 0:    
swap(arr[low++], arr[mid++]);    
break;    
// Here mid is 1.    
case 1:    
mid++;    
break;    
// Here mid is 2.    
case 2:    
swap(arr[mid], arr[high--]);    
break;    
}    
}    
}    

void printArray(int arr[], int arr_size)    
{    
   
for (int i = 0; i < arr_size; i++)    
cout << arr[i] << " ";    
}    
  
int main()    
{    
int arr[] = {0,1,0,1,2,0,1,2};    
int n = sizeof(arr)/sizeof(arr[0]);    
cout << "Array before executing the algorithm: ";    
printArray(arr, n);     
JTP(arr, n);    
cout << "\nArray after executing the DNFS algorithm: ";    
printArray(arr, n);    
return 0;    
}  
