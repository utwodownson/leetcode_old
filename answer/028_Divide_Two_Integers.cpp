/**
 * Divide two integers without using multiplication, division and mod operator.
 */

class Solution {
    public:
        int divide(int dividend, int divisor) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int a = dividend;
            int b = divisor;
            int flag = 1;
            if (a > 0) {
                a = -a;
                flag = -flag;
            }   
            if (b > 0) {
                b = -b;
                flag = -flag;
            }   

            int result = 0;
            if (b == 0) {
                return 0;
            }   

            int k = 0;
            for ( ; b >= (a + 1) >> 1; ++k) 
                b <<= 1;

            while (k >= 0 && a <= b) {
                a -= b;
                result += 1 << k;
                while (a > b) {
                    b = (b + 1) >> 1;
                    k--;
                }   
            }   
            return flag > 0 ? result : -result;
        }   
};
