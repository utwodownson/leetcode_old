/* Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * Each number in C may only be used once in the combination.
 * Note:
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 */
class Solution {
        void dfs(vector<int> &num, int target, int level, vector<int> &tmp,
                 vector<vector<int> > &ans) {
            if (target == 0) {
                ans.push_back(tmp);
                return;
            }

            int pre = -1;
            for (int i = level; i < num.size(); ++i) {
                if (pre == num[i]) continue;

                if (target < num[i]) return;

                pre = num[i];

                tmp.push_back(num[i]);
                dfs(num, target - num[i], i + 1, tmp, ans);
                tmp.pop_back();
            }
        }
    public:
        vector<vector<int> > combinationSum2(vector<int> &num, int target) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            sort(num.begin(), num.end());
            vector<vector<int> > ans;
            vector<int> tmp;
            dfs(num, target, 0, tmp, ans);
            return ans;
        }
};
