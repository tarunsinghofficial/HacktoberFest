/*Q3. Write a program that declares an array as #define and print max number from that array*/
#include <stdio.h>
#define arrVal 10,11,9
void main(){

	int arr[3]={arrVal};

	if(arr[0]>arr[1] && arr[0]>arr[2])
		printf("%d is maximum\n",arr[0]);
	
	else if(arr[1]>arr[0] && arr[1]>arr[2])
		printf("%d is maximum\n",arr[1]);
	
	else if(arr[2]>arr[0] && arr[2]>arr[1])
		printf("%d is maximum\n",arr[2]);
}
