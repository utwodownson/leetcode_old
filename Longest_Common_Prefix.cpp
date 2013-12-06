/* Write a function to find the longest common prefix string amongst an array of strings. */
class Solution {
    public:
        string longestCommonPrefix(vector<string> &strs) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if (!strs.size()) return "";

            for (int i = 0; ; ++i) {
                char c = strs[0][i];
                for (int j = 0; j < strs.size(); ++j) 
                    if (strs[j][i] != c || i >= strs[j].length()) 
                        return strs[j].substr(0, i);
            }
        }
};

