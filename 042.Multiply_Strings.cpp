/**
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 * 
 * Note: The numbers can be arbitrarily large and are non-negative.
 */

class Solution {
    public:
        string multiply(string num1, string num2) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int n = num1.length();
            int m = num2.length();
            vector<int> tmp(n + m, 0);
            for (int i = n - 1; i >= 0; --i) {
                for (int j = m - 1; j >=0; --j) {
                    int c = (num1[i] - '0') * (num2[j] - '0');
                    for (int k = i + j + 1; c > 0; --k) { // k = i + j + 1; c > 0
                        int sum = c + tmp[k];
                        tmp[k] = sum % 10;
                        c = sum / 10;
                    }
                }
            }
            string ans;
            int prezero = 0;
            for ( ; prezero < m + n && tmp[prezero] == 0; ++prezero);
            if (prezero == m + n) {
                ans = "0";
            } else {
                while (prezero < m + n) 
                    ans.push_back(tmp[prezero++] + '0');
            }
            return ans;
        }
};
