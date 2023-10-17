//WAP TO READ AND WRITE INETEGER,CHARACTER,FLOAT VALUE

#include<stdio.h>
int main()
{   // for Integer value
    int a;
    printf("enter Integer value");
    scanf("%d",&a);
    printf("Integer Value is %d",a);

    // for  Character value
    char b;
    printf("\nenter charater value");
    scanf("%s",&b);
    printf("Character Value is %c",b);
    
    // for Float value
    float c;
    printf("\nenter float value");
    scanf("%f",&c);
    printf("float value is %f",c);
    
    return 0;
}