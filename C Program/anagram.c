#include <stdio.h>  
  
//function definition  
int get_anagram (char [],char []);  
  
  
int main ()  
{  
    //declaration of the array  
    char arr1 [50], arr2 [50];  
    int count;  
      
    printf (" Enter the first string: \n ");  
    scanf (" %s", arr1);  
      
      
    printf (" Enter the second string: \n ");  
    scanf (" %s", arr2);  
      
    //call function  
    count = get_anagram (arr1, arr2);  
      
    //use if-else statement to validate both strings are anagram or not.  
      
    if (count == 1)  
    {  
        printf (" %s and %s strings are an anagram of each other. \n", arr1, arr2);  
    }  
    else  
    {  
        printf (" %s and %s strings are not an anagram of each other. \n", arr1, arr2);  
    }  
      
    return 0;  
}  
  
  
//function defnition  
int get_anagram (char arr1[], char arr2[])  
{  
    //create two num arrays and initialize their value as 0  
    int num1[20] = {0}, num2[20] = {0}, i = 0;  
      
    //use while loop to check arr1 is not null  
    while (arr1[i] != '\0')  
    {  
        num1[arr1[i] -'a']++;  
        i++;  
    }  
      
    i = 0;  
      
    //use while loop to check arr2 is not null  
    while (arr2[i] != '\0')  
    {  
        num2[arr2[i] -'a']++;  
        i++;  
    }  
      
    for ( i = 0;i <20; i++)  
    {  
        if ( num1[i] != num2[i])  
            return 0;  
    }  
    return 1;  
}  
