/* Given an encoded message containing digits, determine the total number of ways to decode it.
 * For example,
 * Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
 * The number of ways decoding "12" is 2.
 */
class Solution {
    bool ok(char a) {
        return '1' <= a && a <= '9';
    }
    bool ok(char a, char b) {
        if (a == '1')
            return '0' <= b && b <= '9';
        else if (a == '2')
            return '0' <= b && b <= '6';
        else 
            return false;
    }
    public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0) return 0;
        vector<int> d(n + 1, 0);

        d[0] = 1;

        for (int i = 1; i <= n; ++i) {
            if (ok(s[i - 1]))
                d[i] += d[i - 1];
            if (i >= 2)
                if (ok(s[i - 2], s[i - 1]))
                    d[i] += d[i - 2];
        }
        return d[n];
    }
};

