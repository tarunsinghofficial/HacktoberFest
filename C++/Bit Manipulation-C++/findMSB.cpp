/*
    Problem Link: https://www.codingninjas.com/codestudio/problems/find-msb-in-o-1_1112570?leftPanelTab=2
    Time Complexity: O(1) solution to find the nearest power of 2 <= n
    Space complexity: O(1)
*/

#include <iostream>
using namespace std;

int findMSB(int n) {
    
    n = n | n >> 1;
    n = n | n >> 2;
    n = n | n >> 4;
    n = n | n >> 8;
    n = n | n >> 16;

    n = n + 1;

    return (n >> 1);
}

int main() {

    int n;
    cin >> n;
    cout << findMSB(n) << "\n";

}