#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void sortString(char str[]) {
    int n = strlen(str);
    for(int i = 0; i < n-1; i++)
        for(int j = i+1; j < n; j++)
            if(str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
}

int main() {
    char str1[MAX], str2[MAX];

    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    sortString(str1);
    sortString(str2);

    if(strcmp(str1, str2) == 0)
        printf("The strings are anagrams.\n");
    else
        printf("The strings are NOT anagrams.\n");

    return 0;
}
