//This is a simple program to convert an interger to it's binary(2's complement in case of negative number).
#include <stdio.h>

int main(){
	short int no;//remove short keyword for 32 bit
	int bits=16;//change this to 32 for 32 bit
	printf("Enter integer to be converted to binary:");
	scanf("%d",&no);
	for (int i=0;i<bits;i++){
		printf("%d",(no&(1<<bits-1-i))?1:0);
	}
}
