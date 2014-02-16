/* Divide two integers without using multiplication, division and mod operator.  */
class Solution {
    public:
        int divide(int dividend, int divisor) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            int sign = 1;
            if (dividend == 0) return 0;
            if (dividend < 0) sign = -sign;
            if (divisor < 0) sign = -sign;
            unsigned int dvd = dividend > 0 ? dividend : -dividend;
            unsigned int dvs = divisor > 0 ? divisor : -divisor;
            unsigned int inc[32];
            unsigned int migValue = dvs;
            int i = 0;

            while (migValue > 0 && migValue <= dvd) {
                inc[i] = migValue;
                migValue = migValue << 1;
                i++;
            }
            i--;
            unsigned int res = 0;
            while (i >= 0 && dvd != 0) {
                if (dvd >= inc[i]) {
                    dvd = dvd - inc[i];
                    res += 1 << i;
                }
                i--;
            }
            return res * sign;
        }
};
