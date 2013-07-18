/**
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * 
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */

class Solution {
    public:
        vector<vector<int> > permuteUnique(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(num.begin(), num.end());
            int n = num.size();
            vector<vector<int> > ret;

            while (1) {            
                ret.push_back(num);

                int p = n - 1;            
                while (p > 0 && num[p-1] >= num[p]) p--;
                if (p == 0) break;

                for (int i = p, j = n - 1; i < j; i++, j--) {
                    swap(num[i], num[j]);
                }
                for (int i = p; i < n; i++) {
                    if (num[i] > num[p-1]) {
                        swap(num[i], num[p-1]);
                        break;
                    }
                }                        
            }
            return ret;
        }
};
