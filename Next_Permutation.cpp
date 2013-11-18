/* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
 * The replacement must be in-place, do not allocate extra memory.
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */
class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int n = num.size();
            int p = n - 1;
            while (p > 0 && num[p - 1] >= num[p]) p--;
            for (int i = p, j = n - 1; i < j; ++i, --j) swap(num[i], num[j]);
            if (p > 0) {
                for (int i = p; i < n; ++i) {
                    if (num[i] > num[p - 1]) {
                        swap(num[i], num[p - 1]);
                        break;
                    }
                }
            }
        }
};
