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
            int i = 0, j = 0, k = 0;
            for (i = num.size() - 1; i > 0 && num[i - 1] >= num[i]; --i); 
            for (j = i, k = num.size() - 1; j < k; ++j, --k) swap(num[j], num[k]);
            for (j = i; j < num.size(); ++j)
                if (num[j] > num[i - 1]) {
                    swap(num[i - 1], num[j]);
                    return;
                }
        }
};
