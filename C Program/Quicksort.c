#include<stdio.h>

/* This function is the implementation of quick sort */ 
void quicksort(int number[], int first, int last) {
   int i, j, pivot, temp;

   if (first < last) {
      pivot = first;
      i = first;
      j = last;

      while (i < j) {
         while (number[i] <= number[pivot] && i < last)
            i++;
         while (number[j] > number[pivot])
            j--;
       
