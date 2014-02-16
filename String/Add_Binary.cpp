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
            int na = a.length(), nb = b.length();
            string ans;
            int c = 0;
            int i = na - 1, j = nb - 1, k = na + nb;
            while (i >= 0 || j >= 0) {
                int tmp = c;
                if (i >= 0) tmp += a[i--] - '0';
                if (j >= 0) tmp += b[j--] - '0';
                ans.push_back(tmp % 2 + '0');
                c = tmp / 2;
            }
            if (c) ans.push_back(c + '0');
            reverse(ans.begin(), ans.end());
            return ans;
        }
};

