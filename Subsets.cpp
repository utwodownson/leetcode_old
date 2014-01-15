/* Given a set of distinct integers, S, return all possible subsets.
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,3], a solution is:
 * 
 * [
 *   [3],
 *   [1],
 *   [2],
 *   [1,2,3],
 *   [1,3],
 *   [2,3],
 *   [1,2],
 *   []
 * ]
 */
class Solution {
    void subsets(vector<int> &S, vector<int> &tmp, int step, vector<vector<int> > &ans) {
        if (step == S.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(S[step]);
        subsets(S, tmp, step + 1, ans);
        tmp.pop_back();

        subsets(S, tmp, step + 1, ans);
    }
public:
    vector<vector<int> > subsets(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> tmp;
        subsets(S, tmp, 0, ans);
        return ans;
    }
};
