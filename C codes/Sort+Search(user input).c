#include <stdio.h>
#include <stdlib.h>

void display(int arr[], int n)
{
    int i;
    for(i=0;i<n;i++){
        printf("%d  ", arr[i]);
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int size){

   int i, j,k, min;

   printf("\nCurrent Array: ");
   display(arr, size);
   int passes = 0;
   int comparision = 0;

    for (i = 0; i < size-1; i++)
    {
        min = i;
        for (j = i+1; j < size; j++){
           comparision++;
          if (arr[j] < arr[min])
            min = j;
         }
        swap(&arr[min], &arr[i]);
         passes++;

    }
    printf("\nSORTED ARRAY.");
    display(arr,size);
      printf("\n passes: %d; comparision : %d\n",passes, comparision);
}

void bubbleSort(int arr[], int n)
{
    int i,k,j,temp,count,passes;
    count=0;
    passes=0;
    printf("\n Current Array: ");
    display(arr,n);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            count++;
            if( arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        passes++;
    }
    printf("\n SORTED ARRAY: ");
    display(arr,n);
    printf("\nSorting completed with %d passes and %d comparisons.",passes,count);
}
void insertionSort(int arr[], int size){
int i,j,k,key,passes,comparision;
    printf("\n Current Array: ");
    display(arr,size);
   passes = 0;
   comparision = 0;
   for (int i = 1; i < size; i++) {
      int key = arr[i];
      int j = i-1;
      while (key < arr[j] && j >= 0) {
         arr[j + 1] = arr[j];
         --j;
         comparision++;
      }
      arr[j + 1] = key;
      passes++;
  }
  printf("\nSORTED ARRAY: ");
  display(arr,size);
   printf("\n passes: %d; comparision : %d\n",passes, comparision);
}

int main(){
int ch,cont;
int flag =1;
while(flag){
    printf("\nSORTING");
    printf("\n1. Selection Sort");
    printf("\n2. Bubble Sort");
    printf("\n3. Insertion Sort");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);
    int n,i;
        printf("\n Enter the size of the array: ");
        scanf("%d", &n);
        int arr[n];
        printf("\nEnter the elements of the array: ");
        for(i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }
    switch(ch){
    case 1:
        selectionSort(arr,n);
        printf("\nDo you want to do sorting again???(Press 0 for yes and any number for no.");
        scanf("%d", &cont);
        if(cont == 0){
            break;
        }
        else{
            search();
        }
    case 2:
        bubbleSort(arr,n);
        printf("\nDo you want to do sorting again???(Press 0 for yes and any number for no.");
        scanf("%d", &cont);
        if(cont == 0){
            break;
        }
        else{
            search();
        }
    case 3:
        insertionSort(arr,n);
        printf("\nDo you want to do sorting again???(Press 0 for yes and any number for no.");
        scanf("%d", &cont);
        if(cont == 0){
            break;
        }
        else{
            search();
        }
    }
}

}

void linearSearch(int arr[], int n, int count){
    int key, i;
printf("\nEnter the element you want to search: ");
scanf("%d",&key);
for(int i=0;i<n;i++){
    if(arr[i]==key){
        printf("\n Element %d found at %d index on %d comparisions.", key, i, i+1);
    }
}
}

int checkSorted(int arr[], int size)
   {
      int flag = 1;
      for (int i = 0; i < size - 1; i++)
      {
         if (arr[i] > arr[i + 1])
         {
            flag = 0;
            break;
         }
      }
      if (flag == 1)
      {
         return 1;
      }
      else
      {
         return 0;
      }
   }

   void binarySearch(int arr[], int l, int r,int count)
{
    int x;
    printf("\nEnter the elment you want to search: ");
    scanf("%d", &x);
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x){
                count++;
            printf("\nElement found at index %d after %d comparisons.",mid, count);
        }



        if (arr[mid] > x){
                count++;
             binarySearch(arr, l, mid - 1,count);
        }
        else if(arr[mid]<x){
                count++;
         binarySearch(arr, mid + 1, r,count);
        }
    }
    else{
        printf("Element not found.");
    }

}

void interpolationSearch(int arr[], int lo, int hi, int count)
{
    int pos;
        int x;
    printf("\nEnter the elment you want to search: ");
    scanf("%d", &x);
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
        pos = lo
              + (((double)(hi - lo) / (arr[hi] - arr[lo]))
                 * (x - arr[lo]));
        if (arr[pos] == x){
                count++;
            printf("Found at index %d after %d comparisons ", pos, count);
        }
        if (arr[pos] < x){
                count++;
            return interpolationSearch(arr, pos + 1, hi,count);
        }
        if (arr[pos] > x){
            count++;
             interpolationSearch(arr, lo, pos - 1,count);
        }
    }
    else{
        printf("\nELEMENT NOT FOUND.");
    }
    return -1;
}




void search(){
    int ch;
    while(1){
        printf("\nSEARCHING");
        printf("\n1. Linear Search.");
        printf("\n2. Binary Search.");
        printf("\n3. Interpolation Search");
        printf("\n Enter choice: ");
        scanf("%d", &ch);
        int n,i,cont,sc;
        printf("\n Enter the size of the array: ");
        scanf("%d", &n);
        int arr[n];
        printf("\nEnter the elements of the array: ");
        for(i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        switch(ch){
    case 1:
        linearSearch(arr, n,0);
        printf("\nDo you want to continue searching?[0 for yes, 1 for no]");
        scanf("%d", &cont);
        if(cont ==0){
                printf("\nARRAY IS ALREADY SORTED: ");
            search();
        }
        else{
            exit(1);
        }
    case 2:
        if(checkSorted(arr,n)){
            binarySearch(arr,0,n-1,0);
            printf("\nDo you want to continue searching?[0 for yes, 1 for no]");
        scanf("%d", &cont);
        if(cont ==0){
            search();
        }
        else{
            exit(1);
        }
        }
        else{
            printf("\nArray is not sorted.");
            printf("\n Which sort you want to apply?");
            printf("\n1. Bubble Sort");
            printf("\n2. Insertion Sort");
            printf("\n3. Selection Sort");
            scanf("%d", &sc);
            switch(sc){
        case 1:
            bubbleSort(arr,n);
            binarySearch(arr,0,n-1,0);
            printf("\nDo you want to continue searching?[0 for yes, 1 for no]");
        scanf("%d", &cont);
        if(cont ==0){
            search();
        }
        else{
            exit(1);
        }
        case 2:
            insertionSort(arr,n);
            binarySearch(arr,0,n-1,0);
            printf("\nDo you want to continue searching?[0 for yes, 1 for no]");
        scanf("%d", &cont);
        if(cont ==0){
            search();
        }
        else{
            exit(1);
        }
        case 3:
            selectionSort(arr,n);
            binarySearch(arr,0,n-1,0);
            printf("\nDo you want to continue searching?[0 for yes, 1 for no]");
        scanf("%d", &cont);
        if(cont ==0){
            search();
        }
        else{
            exit(1);
        }


            }

        }
        case 3:
            if(checkSorted(arr,n)){
            interpolationSearch(arr,0,n-1,0);
            printf("\nDo you want to continue searching?[0 for yes, 1 for no]");
        scanf("%d", &cont);
        if(cont ==0){
                printf("\nARRAY IS ALREADY SORTED: ");
            search();
        }
        else{
            exit(1);
        }
        }
        else{
            printf("\nArray is not sorted.");
            printf("\n Which sort you want to apply?");
            printf("\n1. Bubble Sort");
            printf("\n2. Insertion Sort");
            printf("\n3. Selection Sort");
            scanf("%d", &sc);
            switch(sc){
        case 1:
            bubbleSort(arr,n);
            interpolationSearch(arr,0,n-1,0);
            printf("\nDo you want to continue searching?[0 for yes, 1 for no]");
        scanf("%d", &cont);
        if(cont ==0){
            search();
        }
        else{
            exit(1);
        }
        case 2:
            insertionSort(arr,n);
            interpolationSearch(arr,0,n-1,0);
            printf("\nDo you want to continue searching?[0 for yes, 1 for no]");
        scanf("%d", &cont);
        if(cont ==0){
            search();
        }
        else{
            exit(1);
        }
        case 3:
            selectionSort(arr,n);
            interpolationSearch(arr,0,n-1,0);
            printf("\nDo you want to continue searching?[0 for yes, 1 for no]");
        scanf("%d", &cont);
        if(cont ==0){
            search();
        }
        else{
            exit(1);
        }


            }

        }


        }
    }
}
