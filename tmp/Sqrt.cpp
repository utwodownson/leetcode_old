/* Implement int sqrt(int x).
 * Compute and return the square root of x.
 */
class Solution {
    public:
        int sqrt(int x) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            if (x <= 0) return 0;

            long long low = 1, high = x, mid;

            while (low <= high) {
                mid = low + high >> 1;
                if (mid * mid > x)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
            return low - 1;
        }
};
