class Solution {
    public:
        bool isPalindrome(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int tmp = 0, y = x;
            if (x < 0) return false;
            while (x) {
                tmp = tmp * 10 + x % 10;
                x /= 10;
            }
            if (y == tmp) return true;
            else          return false;
        }
};
