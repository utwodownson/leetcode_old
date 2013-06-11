#include <iostream>
#include <cmath>
using namespace std;

class Solution {
    public:
        double pow(double x, int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (n == 0) return 1;
            double tmp = pow(x, abs(n / 2));
            double result = n & 1 ? tmp * tmp * x : tmp * tmp;
            return n > 0 ? result : 1.0 / result;
        }
};

int main() {
    Solution s;
    double x;
    int n;
    while (cin >> x >> n) {
        cout << s.pow(x, n) << endl;
    }
    return 0;
}
