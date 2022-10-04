//Tower Of Hanoi 
#include<stdio.h>
int TOH(int n,int A,int B,int C){
    if(n>0){
        TOH(n-1,A,C,B);
        printf("From %d to %d (%d,%d)\n",A,C,A,C);
        TOH(n-1,B,A,C);


    }
}
int main()
{
    printf("\n******* Tower Of Hanoi ********\n");
    TOH(3,1,2,3);
    printf("******* End ********\n");
    
    return 0;
}