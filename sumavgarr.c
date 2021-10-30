/* write a program find sum and average of given n elements
 in an array.

NAME-KARTIKAY KAPIL
ROLL NO. 31
SECTION- F
BRANCH- CSE         */

#include<stdio.h>
void main()
{
 int sum=0,avg,i,n;
 printf("enter the size of array:");
 scanf("%d\n",&n);
 int arr[n];
 printf("\nenter the values:  ");
 for(i=0;i<n;i++)
 {    scanf("%d",&arr[i]);
      sum=sum+arr[i];
 }
  avg=sum/n;
  printf("\nsum and average are: %d, %d",sum,avg);
}

/*   OUTPUT
kartikay@kartikay-HP-EliteBook-840-G2:~$ gcc sumavgarr.c
kartikay@kartikay-HP-EliteBook-840-G2:~$ ./a.out
enter the size of array:5
enter the values:  2 34 5 7 2
sum and average are: 50, 10


