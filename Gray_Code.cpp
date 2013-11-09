/* The gray code is a binary(二进制的) numeral(数字) system where two successive(连续的) values differ in only one bit.
 * Given a non-negative(非负的) integer(整数) n representing the total number of bits in the code, print the sequence(序列) of gray code. A gray code sequence must begin with 0.
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 * Note:
 * For a given n, a gray code sequence(序列) is not uniquely(独特地) defined(定义).
 * For example, [0,2,3,1] is also a valid gray code sequence according to the above definition(定义).
 * For now, the judge is able to judge based on one instance(实例) of gray code sequence. Sorry about that.
 */
class Solution {
    public:
        vector<int> grayCode(int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int len = 1 << n;
            vector<int> ans;
            vector<bool> visited(len, false);

            for (int i = 0, k = 0; i < len; ++i) {
                ans.push_back(k);
                visited[k] = true;
                int x = 1;
                while (x < len && visited[k ^ x]) {
                    x <<= 1;
                }
                k = k ^ x;
            }
            return ans;
        }
};
