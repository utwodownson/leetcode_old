/**
 * Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place, do not allocate extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = num.size();
            int p = n - 1;
            while (p > 0 && num[p - 1] >= num[p]) p--;
            for (int i = p, j = n - 1; i < j; ++i, --j) {
                int tmp = num[i];
                num[i] = num[j];
                num[j] = tmp;    
            }
            if (p > 0) {
                for (int i = p; i < n; ++i) {
                    if (num[i] > num[p - 1]) {
                        int tmp = num[i];
                        num[i] = num[p - 1];
                        num[p - 1] = tmp;
                        break;
                    }
                }
            }
        }
};
