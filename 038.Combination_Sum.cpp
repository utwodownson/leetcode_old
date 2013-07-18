/**
 * Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 * 
 * The same repeated number may be chosen from C unlimited number of times.
 * 
 * Note:
 * 
 * All numbers (including target) will be positive integers.
 * Elements in a combination (a1, a2, � , ak) must be in non-descending order. (ie, a1 ? a2 ? � ? ak).
 * The solution set must not contain duplicate combinations.
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 */


class Solution {
    bool getbit(int v, int b) {
        return (v & 1 << b);
    }
    void setbit(int &v, int b) {
        v |= 1 << b;
    }
    void unsetbit(int &v, int b) {
        v &= ~(1 << b);
    }

    public:
    void comb(const vector<int> &cands, int s, const vector<int> &f, int target, const vector<int>& preseq, vector<vector<int> > &result) {
        vector<vector<int> > ret;
        if (target == 0) {
            result.push_back(preseq);
            return;
        }
        for (int i = s; i >= 0; i--) {
            if (getbit(f[target], i)) {
                vector<int> pre = preseq;
                pre.push_back(cands[i]);
                comb(cands, i, f, target - cands[i], pre, result);
            }
        }
    }

    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end(), greater<int>());
        vector<vector<int> > ret;
        vector<int> f(target+1, 0);
        f[0] = 1;
        for (int i = 0; i < candidates.size(); i++) {
            for (int j = 1; j <= target; j++) {
                if (j >= candidates[i] && f[j - candidates[i]]) {
                    setbit(f[j], i);
                } else {
                    unsetbit(f[j], i);
                }
            }            
        }

        comb(candidates, candidates.size() - 1, f, target, vector<int>(), ret);
        return ret;
    }
};
