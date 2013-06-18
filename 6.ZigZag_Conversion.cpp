class Solution {
    public:
        string convert(string s, int nRows) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function    
            int len = s.length();
            string str;
            int mid = nRows / 2;
            int d = 0;
            for (int i = 0; i < nRows; ++i) {
                for (int j = i; j < len; j + d) {
                    if (i == mid) {
                        d = nRows - 1;
                        str.push_back(s[j]);
                    } else {
                        d = nRows + 1;
                        str.push_back(s[j]);
                    }
                }
            }
            return str;
        }
};
