#include <stdio.h>
#include <string.h>

void reverse_string(char *str) {
    int n = strlen(str);
    for (int i = 0; i < n / 2; i++) {
        // Swap characters
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    char s[100];

    printf("Enter a string to reverse:\n");
    fgets(s, sizeof(s), stdin); // Use fgets instead of gets

    // Remove the newline character if present
    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
    }

    reverse_string(s); // Call the function to reverse the string

    printf("Reverse of the string: %s\n", s);

    return 0;
}
