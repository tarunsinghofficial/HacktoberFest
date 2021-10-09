/* Problem Link: https://leetcode.com/problems/divide-two-integers/
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        // edge case
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        
        long dvd = labs(dividend), dvs = labs(divisor), result = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        
        while(dvd >= dvs) {
            long temp = dvs, m = 1;
            // find  greatest value of divisor to be subtracted
            while((temp << 1) <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            // subtract max multiple of div
            dvd -= temp;
            result += m;
        }
        return sign * result;
    }
};