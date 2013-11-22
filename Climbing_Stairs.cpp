/* You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
class Solution {
        int fib[100];
    public:
        int climbStairs(int n) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            fib[0] = fib[1] = 1;
            for (int i = 2; i <= n; ++i) 
                fib[i] = fib[i - 1] + fib[i - 2];
            return fib[n];
        }
};
