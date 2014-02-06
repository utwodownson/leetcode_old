/* Given a number represented as an array of digits, plus one to the number.
 */
class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<int> ans;
            int c = 1;
            for (int i = digits.size() - 1; i >= 0; --i) {
                int tmp = digits[i] + c;
                c = tmp / 10;
                ans.push_back(tmp % 10);
            }
            if (c) ans.push_back(c);
            reverse(ans.begin(), ans.end());
            return ans;
        }
};
