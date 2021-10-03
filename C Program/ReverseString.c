#include <stdio.h>  
#include <string.h>  
  
void revstr(char *str1)  
{  
    
    static int i, len, temp;  
    len = strlen(str1); 
      
      
    if (i < len/2){  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
        i++;  
        revstr(str1); 
    }  
}  
      
    int main()  
    {  
        char str1[50]; 
        printf (" Enter the string: ");  
        gets(str1);          
        printf (" \n Before reversing the string: %s \n", str1);    
        revstr(str1);  
        printf (" After reversing the string: %s", str1);  
    }  
