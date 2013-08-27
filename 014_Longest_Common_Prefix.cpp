/*
 * Write a function to find the longest common prefix string amongst an array of strings.
 */

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ans;
        if (strs.size() == 0) return "";
        int len = 0;
        for ( ; ; ) {
            char c;
            int i = 0;
            for ( ; i < strs.size(); ++i) {
                if (i == 0) c = strs[0][len];
                if (strs[i].size() == len || strs[i][len] != c)
                    break;
            }
            if (i != strs.size()) 
                break;
            len++;
            ans.append(1, c);
        }
        return ans;
    }
};
