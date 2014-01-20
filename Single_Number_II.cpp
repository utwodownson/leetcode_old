/* Given an array of integers, every element appears three times except for one. Find that single one.
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */
class Solution {
    public:
        int singleNumber(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> bits(32, 0);
            for (int i = 0; i < n; ++i)
                for (int k = 0; k < 32; ++k)
                    bits[k] += (A[i] >> k) & 1;

            int ret = 0;
            for (int i = 0; i < 32; ++i)
                ret |= (bits[i] % 3) << i;
            return ret;
        }
};
