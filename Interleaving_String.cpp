/* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
 * For example,
 * Given:
 * s1 = "aabcc",
 * s2 = "dbbca",
 * When s3 = "aadbbcbcac", return true.
 * When s3 = "aadbbbaccc", return false.
 */
class Solution {
    int is(int i, int j, string s1, string s2, string s3) {
        if (!i && !j) return true;
        if (i > 0) 
            if (s1[i - 1] == s3[i + j - 1])
                if (is(i - 1, j, s1, s2, s3))
                    return true;
        if (j > 0) 
            if (s2[j - 1] == s3[i + j - 1])
                if(is(i, j - 1, s1, s2, s3))
                    return true;
        return false;
    }
    public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
        if (n1 + n2 != n3) return false;
        return is(n1, n2, s1, s2, s3);
    }
};

