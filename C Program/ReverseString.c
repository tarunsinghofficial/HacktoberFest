#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverseString(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char s[100];

    printf("Enter a string to reverse (max 99 characters): ");
    fgets(s, sizeof(s), stdin); // Use fgets instead of gets

    // Remove the newline character if it exists
    s[strcspn(s, "\n")] = 0;

    reverseString(s); // Call the custom reverse function

    printf("Reverse of the string: %s\n", s);

    return 0;
}
