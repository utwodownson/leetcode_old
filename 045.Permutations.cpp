/**
 * Given a collection of numbers, return all possible permutations.
 * 
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

class Solution {
    vector<vector<int> > ret;
    void perm(vector<int>& p, vector<int>& options, vector<bool>& used) {
        if (p.size() == options.size()) {
            ret.push_back(p);
            return;
        }

        for (size_t i = 0; i < options.size(); i++) {
            if (!used[i]) {
                used[i] = true;
                p.push_back(options[i]);
                perm(p, options, used);
                p.pop_back();
                used[i] = false;
            }
        }
    }

    public:
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ret.clear();
        vector<int> p;
        vector<bool> used(num.size(), false);
        perm(p, num, used);
        return ret;
    }
};
