#include <stdio.h>

/**
 * This function calculates the survivor of the Josephus problem.
 * 
 * @param n The number of people standing in a circle.
 * @param k The number of people to be skipped before an elimination.
 * 
 * @return The position of the survivor.
 */

int josephus(int n, int k) {
    if (n == 1) {
        return 1;
    } else {
        return (josephus(n - 1, k) + k - 1) % n + 1;
    }
}

int main() {
    int n = 6, k = 2;
    printf("The winner is %d\n", josephus(n, k));
    return 0;
}
