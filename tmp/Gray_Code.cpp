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
        int get_next(int now, int n) {
            int num_bit = 0;
            int tmp = now;
            while (tmp > 0) {
                num_bit ^= 1;
                tmp &= (tmp - 1);
            }
            if (num_bit & 1) {
                for (int i = 0; i < n - 1; ++i)
                    if (now & (1 << i))
                        return now ^ (1 << i + 1);
                return 0;
            } else 
                return now ^ 1;
        }
    public:
        vector<int> grayCode(int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> vc;
            int now = 0;
            if (n == 0) {
                vc.push_back(0);
                return vc;
            }
            do {
                vc.push_back(now);
            } while ((now = get_next(now, n)) != 0);
            return vc;
        }
};
