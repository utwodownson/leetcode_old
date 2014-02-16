/* Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 */
class Solution {
        void dfs(vector<int> &nums, int target, int level,
                 vector<int> &tmp, vector<vector<int> > &ans) {
            if (target == 0) {
                ans.push_back(tmp);
                return;
            }

            for (int i = level; i < nums.size(); ++i) {
                if (target < nums[i]) return;
                tmp.push_back(nums[i]);
                dfs(nums, target - nums[i], i, tmp, ans);
                tmp.pop_back();
            }
        }
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            sort(candidates.begin(), candidates.end());
            vector<vector<int> > ans;
            vector<int> tmp;
            dfs(candidates, target, 0, tmp, ans);
            return ans; 
        }
};
