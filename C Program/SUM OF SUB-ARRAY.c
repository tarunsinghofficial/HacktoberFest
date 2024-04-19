#include<stdio.h>
//to write a C program which helps in finding the sum of array elements between two indices
int main()
{
  int size, index;
  printf("Enter the array size:\n");
  scanf("%d",&size); // getting the size of the array
  int arr[size]; 
  
  print("Enter the values for the array:\n");
  for(index = 0; index < size; index++){
    scanf("%d",&arr[index]);
  }
  
  int arr_sum[size]; // declaring an array named arr_sum to store sum of sub array
  
  arr_sum[0] = arr[0]; 
  
  for(index = 1; index < size; index++){
    arr_sum[index] = arr[index] + arr_sum[index-1]; // stores the sum from arr[0] till arr[index] for each sum_arr[index]
  }
  
  int i, j; 
  printf("Enter the index values to get the sum of sub-array:\n");
  scanf("%d %d",&i,&j);
  
  int sum = sum_arr[j] - sum_arr[i-1];
  
  printf("The sum of sub-array between the index %d and %d is %d", i, j, sum);
  
}
  
// Time Complexity: O(n)
// Space Complexity: O(n)
  
  
  
