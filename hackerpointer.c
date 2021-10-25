#include <stdio.h>
#include<stdlib.h>
void update(int *a,int *b) {
    // Complete this function  
    // here we are adding and subtracting using pointers
    //a=a+b,b=a-b;
    *a= *a + *b;
   // *b=abs(*a-(2**b)); since we are using stdlib no explicit use of abs funcn here
     *b=abs(*a-(2**b));  
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
