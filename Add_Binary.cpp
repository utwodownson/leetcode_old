/* Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 */
class Solution {
    public:
        string addBinary(string a, string b) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            int la = a.length(), lb = b.length(), tmp = 0, tmpa, tmpb;
            string ans;
            for (int i = la - 1, j = lb - 1; i >= 0 || j >= 0 || tmp; --i, --j) {
                tmpa = i >= 0 ? a[i] - '0' : tmpa = 0;
                tmpb = j >= 0 ? b[j] - '0' : tmpb = 0;
                int sum = tmp + tmpa + tmpb;
                ans.push_back(sum % 2 + '0');
                tmp = sum / 2;
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
};

