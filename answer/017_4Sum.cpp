/*
 * Given an numay S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? 
 * Find all unique quadruplets in the numay which gives the sum of target.
 * 
 * Note:
 * 
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ? b ? c ? d)
 * The solution set must not contain duplicate quadruplets.
 *     For example, given numay S = {1 0 -1 0 -2 2}, and target = 0.
 * 
 *         A solution set is:
 *             (-1,  0, 0, 1)
 *             (-2, -1, 1, 2)
 *             (-2,  0, 0, 2)
 */
class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > ret;
            int len = num.size();
            sort(num.begin(), num.end());
            for (int i = 0; i < len; ) {
                for (int j = i + 1; j < len; ) {
                    int s1 = num[i] + num[j];
                    for (int k = j + 1, m = len - 1; k < m; ) {
                        int s = s1 + num[k] + num[m];
                        if (s == target) {
                            int q[4] = { num[i], num[j], num[k], num[m]};
                            ret.push_back(vector<int>(q, q + 4));
                            while (++k < m && num[k] == num[k-1]);
                            while (--m > k && num[m] == num[m+1]);
                        } else if (s < target) {
                            while (++k < m && num[k] == num[k-1]);              
                        } else {
                            while (--m > k && num[m] == num[m+1]);
                        }
                    }
                    while (++j < len && num[j] == num[j-1]);
                }
                while (++i < len && num[i] == num[i-1]);
            }
            return ret;
        }
};
