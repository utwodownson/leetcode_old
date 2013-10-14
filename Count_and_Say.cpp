/* The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 * Note: The sequence of integers will be represented as a string.
 */
class Solution {
    public:
        void addNum(string &s, int n) {
            string v;
            while (n) {
                v.push_back(n % 10 + '0');
                n /= 10;
            }
            for (int i = v.length() - 1; i >= 0; --i)
                s.push_back(v[i]);
        }
        string countAndSay(int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            string s = "1";
            while (--n) {
                string t = s;
                s = "";
                for (int i = 0; i < t.length(); ++i) {
                    int cnt = 1;
                    while (t[i] == t[i + 1]) {
                        i++;
                        cnt++;
                    }
                    addNum(s, cnt);
                    s.push_back(t[i]);
                }
            }
            return s;
        }
};
