#include <stdio.h>
#include <string.h>
int main()
{
   char str[10001];
   int i,j,temp,count=0;
   printf("Enter a string: ");
   gets(str);
   for(j=0;str[j]!='\0';j++)
   for(i=0,j=j-1;i<j;i++,j--){
temp=str[i];
str[i]=str[j];
str[j]=swap;
}
printf("Reversed string: %s\n",str);
return 0;
}
