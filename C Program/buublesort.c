#include<stdio.h>

int main(){

   int count, temp, i, j;

   printf("How many numbers are u going to enter?: ");
   scanf("%d",&count);
   int number[count];

   printf("Enter %d numbers:\n ",count);

   for(i=0;i<count;i++){
       printf("Enter %d number: ",i+1);
       scanf("%d",&number[i]);
   }

   for(i=count-2;i>=0;i--){
      for(j=0;j<=i;j++){
        if(number[j]>number[j+1]){
           temp=number[j];
           number[j]=number[j+1];
           number[j+1]=temp;
        }
      }
   }

   printf("Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",number[i]);

   return 0;
}
