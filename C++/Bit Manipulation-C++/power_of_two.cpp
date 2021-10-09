/*
Problem Link: https://practice.geeksforgeeks.org/problems/power-of-2-1587115620/1
Soln: Using Bit manipulation
*/

bool isPowerOfTwo(long long n) {
    if(n == 0)
        return false;
    return (n & (n - 1)) == 0;
}