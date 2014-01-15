/* Given a collection of integers that might contain duplicates, S, return all possible subsets.
 * Note:
 * Elements in a subset must be in non-descending order.
 * The solution set must not contain duplicate subsets.
 * For example,
 * If S = [1,2,2], a solution is:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */
class Solution {
    void generateSub(vector<int> &s, vector<int> &tmp, int step, vector<vector<int> > &ans) {
        if (step >= s.size()) {
            ans.push_back(tmp);
            return;
        }
        tmp.push_back(s[step]);
        generateSub(s, tmp, step + 1, ans);
        tmp.pop_back();

        while (step < s.size() - 1 && s[step] == s[step + 1]) step++;

        generateSub(s, tmp, step + 1, ans);
    }
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
        vector<vector<int> > ans;
        vector<int> tmp;
        generateSub(S, tmp, 0, ans);
        return ans;
    }
};
