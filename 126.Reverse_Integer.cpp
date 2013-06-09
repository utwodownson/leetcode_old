#include <iostream>
#include <cmath>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            if (x < 10 && x > -10) return x;

            char str[20];
            int i = 0, tmp = abs(x), result = 0;

            while (tmp) {
                str[i++] = tmp % 10 + '0';
                tmp /= 10;
            }

            for (int j = 0; j < i; ++j) 
                result = result * 10 + str[j] - '0'; 

            if (x > 0) return result;
            else       return 0 - result;
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
