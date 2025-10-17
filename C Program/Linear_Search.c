// C code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1
 
#include<stdio.h>
int main(){
    int n,k,flag=-1;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("\nEnter the key: ");
    scanf("%d",&k);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("\nEnter array number %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
     if(arr[i]==k){
        flag=i;
        break;
     }
    }
    if(flag==-1)
    printf("Key not found\n");
    else
    printf("Key found at index %d\n",flag);
    return 0;
}
