class Solution {
    public:
        string convert(string s, int nRows) {        
            string output;
            int gap = 2 * nRows - 2;
            if (gap <= 0) gap = 1;
            int len = s.length();
            for (int i = 0; i < nRows; i++) {
                for (int j = i, inc = j*2; j < len; j += inc) {
                    if (inc < gap) {
                        inc = gap - inc;
                    }
                    output.push_back(s[j]);
                }
            }
            return output;
        }
};
