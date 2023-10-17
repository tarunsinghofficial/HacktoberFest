//WAP TO SWAP THE TWO NUMBER USING CALL BY VALUE

#include <stdio.h>

void swap(int *a, int *b);  // Use pointers to modify values

int main() {
    int a, b;
    printf("Enter Value Of A and B: ");
    scanf("%d %d", &a, &b);
    
    printf("Values Before Swap: A = %d, B = %d\n", a, b);
    swap(&a, &b);  // Pass the addresses of a and b
    
    printf("Values After Swap: A = %d, B = %d\n", a, b);
    return 0;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
