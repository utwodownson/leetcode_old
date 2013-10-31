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
            string tmp;
            int i, j;
            char c = '0';
            for (i = a.length()-1, j = b.length()-1; i >= 0 || j >= 0; i--, j--) {
                char t = c;
                if (i >= 0) t += a[i] - '0';
                if (j >= 0) t += b[j] - '0';
                if (t > '1') {
                    t -= 2;
                    c = '1';
                } else {
                    c = '0';
                }
                tmp.push_back(t);
            }
            if (c > '0') tmp.push_back(c);
            string sum;
            for (i = tmp.length()-1; i >= 0; i--) {
                sum.push_back(tmp[i]);
            }
            return sum;                                   
        }
};

