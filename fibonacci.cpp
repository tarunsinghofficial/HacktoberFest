#include <iostream>

int main() {
    int n, firstTerm = 0, secondTerm = 1, nextTerm;

    // Input the number of terms from the user
    std::cout << "Enter the number of terms: ";
    std::cin >> n;

    std::cout << "Fibonacci Series: ";

    for (int i = 1; i <= n; ++i) {
        // Print the first two terms
        if (i == 1) {
            std::cout << firstTerm << ", ";
            continue;
        }
        if (i == 2) {
            std::cout << secondTerm << ", ";
            continue;
        }

        // Generate the next term in the series
        nextTerm = firstTerm + secondTerm;
        firstTerm = secondTerm;
        secondTerm = nextTerm;

        std::cout << nextTerm << ", ";
    }

    return 0;
}
