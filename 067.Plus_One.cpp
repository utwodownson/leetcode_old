/**
 * Given a number represented as an array of digits, plus one to the number.
 */

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int t = 1, c = 0;
            vector<int> ans;
            for (int i = digits.size() - 1; i >= 0; --i) {
                t += digits[i];
                if (t > 9) {
                    digits[i] = 0;
                    c = 1;
                } else {
                    digits[i] = t;
                    c = 0;
                }
                t = c;
            }
            if (t == 1) {
                ans.push_back(t);
            } 
            for (int i = 0; i < digits.size(); ++i) 
                ans.push_back(digits[i]);
            return ans;
        }
};
