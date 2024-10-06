#include <stdio.h>
#include <string.h>

int main() {
    char string1[20];
    int i, length;
    int flag = 0;

    // Prompt the user for input
    printf("Enter a string: ");
    scanf("%s", string1);

    // Calculate the string length
    length = strlen(string1);

    // Compare characters from the start and end of the string
    // and stop if a mismatch is found or the middle of the string is reached.
    for (i = 0; i < length / 2; i++) {
        if (string1[i] != string1[length - i - 1]) {
            flag = 1;
            break;
        }
    }

    // Output the result
    if (flag) {
        printf("%s is not a palindrome\n", string1);
    } else {
        printf("%s is a palindrome\n", string1);
    }

    return 0;
}