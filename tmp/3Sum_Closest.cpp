/* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, 
 * target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */
class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            sort(num.begin(), num.end());
            int closest = 0, flag = 1;

            for (int i = 0; i < num.size(); ++i) {
                for (int j = i + 1, k = num.size() - 1; j < k; ) {
                    int s = num[i] + num[j] + num[k];
                    if (flag || abs(closest - target) > abs(s - target)) {
                        closest = s;
                        flag = 0;
                    }
                    if (s > target) k--;
                    else if (s < target) j++;
                    else return target;
                }
            }
            return closest;
        }
};
