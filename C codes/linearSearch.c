#include <stdio.h>
#include <stdlib.h>


int linearSearch(int arr[], int n, int key){
    int i;
    for(i=0;i<n;i++)
    {
            if(arr[i] == key){
                printf("Element present at  index: %d", i);
                break;
            }
            else if(i== n-1){
                printf("Element not present !!");
            }
    }
}