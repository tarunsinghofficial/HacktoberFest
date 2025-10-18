/***Insertion Sort Algorithm***/

//@Author : SoumyadipGhosh23 (GitHub: https://github.com/SoumyadipGhosh23)

#include<stdio.h>
#include<stdlib.h>

void printArr(int* a, int n){
    for(int i=0; i<n; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

void insertionSort(int* a, int n){
    int temp,j;
    for(int i =1; i<n; i++){
        printf("working on the pass no: %d\n",i);
        temp = a[i];
        j= i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

int main(){
    //int arr[] = {2,36,1,31,10,27,11,78,80,45};
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    printArr(arr,10);
    insertionSort(arr,10);
    printArr(arr,10);
}
