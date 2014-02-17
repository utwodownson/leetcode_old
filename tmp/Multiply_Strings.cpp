/* Given two numbers represented as strings, return multiplication of the numbers as a string.
 * Note: The numbers can be arbitrarily large and are non-negative.
 */
class Solution {
    public:
        string multiply(string num1, string num2) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int up = num1.length(), down = num2.length(), zero;
            string ret;
            vector<int> ans(up + down + 1, 0);

            for (int i = down - 1; i >= 0; --i) {
                for (int j = up - 1; j >= 0; --j) {
                    int c = (num2[i] - '0') * (num1[j] - '0');
                    for (int k = i + j + 1; c > 0; --k) {
                        int sum = c + ans[k];
                        ans[k] = sum % 10;
                        c = sum / 10;
                    }
                }
            }

            for (zero = 0; zero < up + down && ans[zero] == 0; ++zero);
            if (zero == up + down) 
                return "0";
            else 
                for ( ; zero < up + down; ret.push_back(ans[zero++] + '0'));
            return ret;
        }
};
