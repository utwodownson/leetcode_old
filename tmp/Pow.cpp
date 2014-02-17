/* Implement pow(x, n).*/
class Solution {
    public:
        double pow(double x, int n) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            if (n == 0) return 1;

            double r = pow(x, abs(n / 2));
            double ans = n & 1 ? r * r * x : r * r;
            return n > 0 ? ans : 1.0 / ans;
        }
};
