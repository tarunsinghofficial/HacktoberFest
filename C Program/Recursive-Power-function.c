// Finds n^m recursively. . . . (Where n and m are real numbers.)
#include <stdio.h>
#include <stdlib.h>

void* power(int num, int pow)
{
    if(num==0)
    {
        return "Invalid, please input another number";
    }
    else if (pow == 0)
    {
        return (void*)1;    // n^0 ==1 
        
    }
    else if(pow ==1) 
    {
        return (void*)num;
    }
    else if(pow%2==0)      // For all even numbers. 
    {
        int i = *((int*)power(num, pow/2));   
        return (void*)(i*i);                   // Return (x^2)^2... Exponential rule in Indices hahaha
    }
    else 
    return (void*)(num* *((int*)power(num, pow-1))); 
} 

int main(void)
{
    int pow,num; 
    printf("****    HACKTOBERFEST 2023!      ****");
    printf("Enter the number and it's power\n");
    scanf("%d %d", &num ,&pow);
    printf("%d to the power %d = %d\n", num, pow, *((int*)power(num, pow)));
    return 0;
}
