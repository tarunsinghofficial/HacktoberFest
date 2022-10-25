#include <stdio.h>
int LinearSearch(int arr[ ], int index, int item) {
  if(arr[index] == item)
    return index;
  else if(index == -1)
    return -1;
  return LinearSearch(arr, index-1, item);
}
int main() {
  int n;
  printf("Enter the number of elements: ");
  scanf("%d",&n);
  int arr[n];
  printf("Enter the Array elements: ");
  for(int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);
  int item;
  printf("Enter the element to be searched : ");
  scanf("%d", &item);
  int index = LinearSearch(arr, n-1, item);
  if(index < 0) 
    printf("Element is not found");
  else if(index == 0) 
    printf("Best case O(1)");
  else if(index == n -1) 
    printf("Worst case O(n)");
  else 
		printf("Average case O(n)");
	return 0;
}
