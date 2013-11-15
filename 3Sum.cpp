/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 */
class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            sort(num.begin(), num.end());
            vector<vector<int> > ret;
            vector<int> ans(3);

            for (int i = 0; i < num.size(); ++i) {
                int target = -num[i];
                if (i > 0 && num[i] == num[i - 1]) continue;
                for (int j = i + 1, k = num.size() - 1; j < k;) {
                    if (num[j] + num[k] == target) {
                        ans[0] = num[i];
                        ans[1] = num[j];
                        ans[2] = num[k];
                        ret.push_back(ans);
                        for (++j; j < k && num[j] == num[j - 1]; ++j);
                        for (--k; j < k && num[k] == num[k + 1]; --k);
                    } else if (num[j] + num[k] < target) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
            return ret;
        }
};
