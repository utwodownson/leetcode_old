/* Given two numbers represented as strings, return multiplication of the numbers as a string.
 * Note: The numbers can be arbitrarily large and are non-negative.
 */
class Solution {
    public:
        string multiply(string num1, string num2) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int up = num1.length(), down = num2.length(), zero = 0, k;
            string ans;
            vector<int> buf(up + down + 1, 0);

            for (int i = down - 1; i >= 0; --i) {
                for (int j = up - 1; j >= 0; --j) {
                    k = i + j + 1;
                    int tmp = (num2[i] - '0') * (num1[j] - '0') + buf[k];
                    buf[k] = tmp % 10;
                    buf[k - 1] += tmp / 10;
                }
            }

            while (zero < up + down && !buf[zero]) ++zero;
            if (zero == up + down) return "0";
            while (zero < up + down) 
                ans.push_back(buf[zero++] + '0');
            return ans;
        }
};
