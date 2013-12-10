/* You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */
class Solution {
    public:
        int climbStairs(int n) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            int pre = 0, cur = 1;
            for (int i = 1; i <= n; ++i) {
                int tmp = cur;
                cur = pre + cur;
                pre = tmp;
            }
            return cur;
        }
};
