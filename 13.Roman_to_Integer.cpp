#include <iostream>
using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int val = 0, last = 0;
            string name = "IVXLCDM";
            int list[] = { 1, 5, 10, 50, 100, 500, 1000 };
            int len = sizeof(list) / sizeof(int);

            for (int i = 0; i < s.length(); ++i) {
                int v = list[name.find(s[i])];
                if (v <= last)
                    val += last;
                else
                    val -= last;
                last = v;
            }
            val += last;
            return val;
        }
};

int main() {
    Solution s;
    string x;
    while (cin >> x) {
        cout << s.romanToInt(x) << endl;
    }
    return 0;
}
