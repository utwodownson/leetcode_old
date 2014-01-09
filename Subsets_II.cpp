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
    void generateSub(vector<int> &s, int step, vector<vector<int> > &ans, vector<int> &tmp) {
        for (int i = step; i < s.size(); ++i) {
            tmp.push_back(s[i]);
            ans.push_back(tmp);
            if (i < s.size() - 1) 
                generateSub(s, i + 1, ans, tmp);
            tmp.pop_back();
            while (i < s.size() - 1 && s[i] == s[i + 1]) i++;
        }
    }
    public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > ans;
        vector<int> tmp;
        if (!S.size()) return ans;
        ans.push_back(tmp);
        sort(S.begin(), S.end());
        generateSub(S, 0, ans, tmp);
    }
};
