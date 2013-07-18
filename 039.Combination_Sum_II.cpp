/**
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * 
 * Each number in C may only be used once in the combination.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6] 
 */


class Solution {
    void comb(const vector<int> &num, int s, const vector<string> &g, int target, const vector<int> &pre, vector<vector<int> > &result) {
        if (target == 0) {
            result.push_back(pre);
        } else {
            int last = 0;
            for (int i = s; i >= 0; i--) {
                if (g[target][i] == '1' && num[i] != last) {
                    vector<int> preseq = pre;
                    preseq.push_back(num[i]);
                    comb(num, i - 1, g, target - num[i], preseq, result);
                    last = num[i];
                }
            }
        }
    }
    public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end(), greater<int>());

        vector<bool> f(target+1, false);
        vector<string> g(target+1);
        f[0] = true;
        for (int i = 0; i < num.size(); i++) {
            for (int j = target; j > 0; j--) {
                if (j >= num[i] && f[j - num[i]]) {
                    f[j] = true;
                    g[j].push_back('1');
                } else {
                    g[j].push_back('0');
                }
            }
        }

        vector<vector<int> > ret;
        comb(num, num.size() - 1, g, target, vector<int>(), ret);
        return ret;
    }
};
