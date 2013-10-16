/* Given a number represented as an array of digits, plus one to the number.
 */
class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> ans;
            for (int i = digits.size() - 1, c = 1; i >= 0 || c == 1; --i) {
                int val = c;
                if (i >= 0)
                    val += digits[i];
                val = val % 10;
                c = val / 10;
                ans.push_back(val);
            }
            for (int i = 0, j = digits.size() - 1; i < j; ++i, --j)
                swap(ans[i], ans[j]);
            return ans;
        }
};
