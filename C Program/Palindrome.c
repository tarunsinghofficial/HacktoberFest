#include <stdio.h> 
#include <string.h> 
  
// A function to check if a string str is palindrome 
int isPalindrome(char str[]) 
{ 
    // Start from leftmost and rightmost corners of str 
    int l = 0; 
    int h = strlen(str) - 1; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
            return 0; 
     
    } 
    return 1;
} 
  
// Main function to check if entered string is palindrome or not
int main() 
{   //Taking input from user
    printf("Enter a string to check if it's palindrome or not\n");
    char str[100];
    scanf("%s",str);
    if(!isPalindrome(str))
      printf("%s is Not Palindrome",str);
  else printf("%s is Palindrome",str);
}
