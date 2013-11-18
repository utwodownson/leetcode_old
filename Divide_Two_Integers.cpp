/* Divide two integers without using multiplication, division and mod operator.  */
class Solution {
        long long pos(long long a, long long b) {
            if (a == 0) return 0;
            long long low = 0, high = a, mid;
            while (low <= high) 
                if ((mid = low + high >> 1) * b > a)
                    high = mid - 1;
                else
                    low = mid + 1;
            return low - 1; 
        }
    public:
        int divide(int dividend, int divisor) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            long long a = dividend;
            long long b = divisor;

            int signa = 0, signb = 0;
            if (a < 0) { signa = 1; a = -a; }
            if (b < 0) { signb = 1; b = -b; }

            long long ret = pos(a, b);

            if (signa ^ signb) return -ret;
            return ret;
        }
};
