class Solution {
public:
    int divide(int dividend, int divisor) {
      int sign = (dividend<0) ^ (divisor<0)?-1:1;
        long dvd = dividend;
        long dvs = divisor;
        dvd = abs(dvd);
        dvs = abs(dvs);
        int ret = 0;
        for (int i = 31; i>=0; --i) {
            if (dvd>>i >= dvs) {
                // overflow
                if (i==31) {
                    return sign>0?INT_MAX:INT_MIN;
                }
                ret += 1<<i;
                dvd -= dvs<<i;
            }
        }
        return sign>0 ? ret : -ret;   
    }
};