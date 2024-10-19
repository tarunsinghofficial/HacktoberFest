#include <stdio.h>
#include <string.h>

void reverseString(char* str) {
    int start = 0;
    int end = strlen(str) - 1;
    char temp;

    while (start < end) {
        // Swap characters
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;

        start++;
        end--;
    }
}

int main() {
    char s[100];

    printf("Enter a string to reverse: ");
    fgets(s, sizeof(s), stdin);

    // Remove newline character if present
    s[strcspn(s, "\n")] = '\0';

    reverseString(s);

    printf("Reverse of the string: %s\n", s);

    return 0;
}
