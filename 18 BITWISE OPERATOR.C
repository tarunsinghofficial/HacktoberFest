// WAP TO SHOW THE WORKING OF BITWISE OPERATOR i.e., &,!,^,~,>>,<<

#include<stdio.h>
int main()
{
    int a,b;
    a=12,b=25;
    printf("Bitwise And Operation is %d",a & b);
    printf("\nBitwise Or Operation is %d", a | b);
    printf("\nBitwise XOR Operation is %d",a ^ b);
    printf("\n1s Complement is %d",~35);  // complement of positive value gives 1s complement
    printf("\n2s Complement is %d",~-12); // complement of negative value gives 2s complement
    printf("\nRight Shift is %d",212>>2); // in binary it shifts 2 bits to right
    printf("\nLeft Shift is %d",212<<2);  // in binary it shifts 2 bits to right
}