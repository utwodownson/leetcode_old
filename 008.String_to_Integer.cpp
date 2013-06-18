#include <iostream>
#include <cassert>
#include <climits>
using namespace std;

class Solution {
    public:
        int atoi(const char *str) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            assert(str);    // NULL
            int min_neg = INT_MIN; //static int min_neg = 1 << (sizeof(int)*8 - 1);
            int max_pos = INT_MAX; //static int max_pos = ~min_neg;
            int ans = 0;
            bool sign = true;
            // 
            while (isspace(*str)) str++;
            //
            if (*str == '+') str++;
            else if (*str == '-') { str++; sign = false; }
            //
            while (*str <= '9' && *str >= '0') {

                int dig = *str - '0';

                if (sign) {
                    if (ans > (max_pos - dig) / 10) {
                        ans = max_pos;
                        break;
                    }
                    ans = ans * 10 + dig;
                } else {
                    if (ans < (min_neg + dig) / 10) {
                        ans = min_neg;
                        break;
                    }
                    ans = ans * 10 - dig;
                }            
                str++;
            }

            return ans;
        }  
};

int main(void) {
    Solution s;
    string buff;

    while (cin >> buff) 
        cout << s.atoi(buff.substr(0, buff.length()).c_str()) << endl;

    return 0;
}
