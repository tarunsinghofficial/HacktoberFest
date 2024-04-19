#include <stdio.h>
#include <stdlib.h>
void swap(int *a,int *b){
  int temp;
  temp=*a;
  *a=*b;
  *b=temp;
}
void heapify(int *arr,int n,int i){
  int largest=i;
  int left_child=2*i+1;
  int right_child=2*i+2;
  if(left_child<n && arr[left_child]>arr[largest])
  largest=left_child;
  if(right_child<n && arr[right_child]>arr[largest])
  largest=right_child;
  if(largest!=i){
    swap(&arr[largest],&arr[i]);
    heapify(arr,n,largest);
  }
}
void heap_sort(int *arr,int N){
  for(int i=N/2-1;i>=0;i--){
    heapify(arr,N,i);
  }
  for(int i=N-1;i>=0;i--){
    swap(&arr[0],&arr[i]);
    heapify(arr,i,0);
  }
}
void print_array(int *arr,int N){
  for(int i=0;i<N;i++){
    printf("%d  ",arr[i]);
  }
  printf("\n");
}
int main(){
  int N;
  printf("Enter the number of elements in the array\n");
  scanf("%d",&N);
  int *arr=malloc(N*sizeof(*arr));
  printf("\nEnter the elements of array\n");
  for(int i=0;i<N;i++){
    scanf("%d",&arr[i]);
  }
  printf("\nGiven array is\n");
  print_array(arr,N);
  heap_sort(arr,N);
  printf("\nSorted array is\n");
  print_array(arr,N);
}
