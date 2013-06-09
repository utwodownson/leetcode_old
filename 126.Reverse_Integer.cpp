#include <iostream>
#include <cmath>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int sign = x < 0 ? -1 : 1;
            x = abs(x);
            int y = 0;
            while (x > 0) {
                y = y * 10 + x % 10;
                x /= 10;
            }
            return y * sign;
        }
};

int main() {
    Solution s;
    int x;
    while (cin >> x) {
        cout << s.reverse(x) << endl;
    }
    return 0;
}
