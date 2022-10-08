#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int binarySearch(int array[], int elemenst, int search_data);

int main(){
    int numbers[5] = {12, 15, 32, 45, 67}; //array should be orderd
    int serch_data = 32;
    int found = binarySearch(numbers, 5, serch_data);
    printf("%d \n", found);
}


int  binarySearch(int array[], int elements, int search_data){
    int left = 0;
    int right = elements - 1;
    int mid = (left + right)/2;

    while(left<=right){
        if(search_data == array[mid]){
            return mid;
        }else if(search_data > array[mid]){
            left = mid + 1;
        }else if(search_data < array[mid]){
            right = mid - 1;
        }
    }
    return -1;
}
