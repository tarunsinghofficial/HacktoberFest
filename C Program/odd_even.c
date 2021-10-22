#include <stdio.h>
#include<conio.h>

void main()
{
    int a;
    printf("enter a number to check even or odd\n");
    scanf("%d",&a);
    if(a%2==0){
        
        printf("%d is even",a);
    }else{
        
        printf("%d is odd",a);
        
    }
    
    getch();


}
