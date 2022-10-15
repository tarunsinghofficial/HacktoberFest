// program to print fibanoci series using recursion

#include<stdio.h>
void fiba(int n){
    static int n1=0,n2=1,n3;
    if(n>0){
    n3=n1+n2;
    n1=n2;
    n2=n3;
    printf(" %d ",n3);
    fiba(n-1);
    }
}
int main(){
    int z;
    printf("Number:");
    scanf("%d",&z);
    printf("\nFIBANOCCI SERIES\n");
    printf("0 1 ");
    fiba(z-2);
    
}
/* OUTPUT
Number:5

FIBANOCCI SERIES
0 1  1  2  3
*/
