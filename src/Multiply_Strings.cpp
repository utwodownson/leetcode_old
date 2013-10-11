/* Given two numbers represented as strings, return multiplication of the numbers as a string.
 * Note: The numbers can be arbitrarily large and are non-negative.
 */
class Solution {
    public:
        string multiply(string num1, string num2) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int l1 = num1.length();
            int l2 = num2.length();
            vector<int> ans(l1 + l2, 0);

            for (int i = l1 - 1; i >= 0; --i) {
                for (int j = l2 - 1; j >= 0; --j) {
                    int c = (num1[i] - '0') * (num2[j] - '0');
                    for (int k = i + j + 1; c > 0; k--) {
                        int sum = c + ans[k];
                        ans[k] = sum % 10;
                        c = sum / 10;
                    }
                }
            }
            string ret;
            int num_zero = 0;
            while (num_zero < l1 + l2 && ans[num_zero] == 0) num_zero++;
            if (num_zero == l1 + l2)
                ret = "0";
            else {
                while (num_zero < l1 + l2)
                    ret.push_bakc(ans[num_zero++] + '0');
            }
            return ret;
        }
};
