/* Given a number represented as an array of digits, plus one to the number.
 */
class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int n = digits.size(), pre, i;
            vector<int> ans = digits;
            for (i = n - 1, pre = 1; i >= 0 && pre == 1; --i) {
                int tmp = ans[i] + pre;
                ans[i] = tmp % 10;
                pre = tmp / 10;
            }
            if (pre) ans.insert(ans.begin(), pre);
            return ans;
        }
};
