/* Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * Note:
 * If there is no such window in S that covers all characters in T, return the emtpy string "".
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */
class Solution {
public:
    string minWindow(string S, string T) {
        int s = 0, e = 0, total = 0, num = 0;

        vector<int> count(256, 0);
        vector<int> gt(256, 0);

        string minWindow;
        
        for (int i = 0; i < T.length(); i++) {
            gt[T[i]]++;
            if (gt[T[i]] == 1) total++;
        }
        
        while (e < S.length()) {
            count[S[e]]++;
            if (count[S[e]] == gt[S[e++]]) num++;

            while (s < S.length() && num >= total) {
                count[S[s]]--;
                if (count[S[s]] < gt[S[s]]) {
                    num--;
                    if (minWindow.empty() || minWindow.length() > e - s) {
                        minWindow = S.substr(s, e - s);
                    }                        
                }
                s++;
            }
        }
        return minWindow;
    }
};
