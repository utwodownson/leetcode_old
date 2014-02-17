/* Given a string S and a string T, count the number of distinct subsequences of T in S.
 * A subsequence of a string is a new string which is formed from the original string by deleting some 
 * (can be none) of the characters without disturbing the relative positions of the remaining characters. 
 * (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
 * Here is an example:
 * S = "rabbbit", T = "rabbit"
 * Return 3.
 */
class Solution {
    public:
        int numDistinct(string S, string T) {
            int ss = S.length(), st = T.length();
            vector<int> count(st + 1, 0);
            count[0] = 1;
            for (int i = 0; i < ss; ++i) 
                for (int j = st; j >= 0; --j) 
                    if (S[i] == T[j - 1])
                        count[j] += count[j - 1];
            return count[st];
        }
};
