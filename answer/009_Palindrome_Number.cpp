/*
 * Determine whether an integer is a palindrome. Do this without extra space.

 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 *
 * If you are thinking of converting the integer to string, 
 * note the restriction of using extra space.
 *  
 * You could also try reversing an integer. However, 
 * if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
 * How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 */
 /* bad alg
class Solution {
    public:
        bool isPalindrome(int x) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int y = 0, tmp = abs(x);
            int sign = x > 0 ? 1 : -1;
            while (tmp) {
                y = y * 10 + tmp % 10;
                tmp /= 10;
            }
            if (x == y) return true;
            else return false;
        }
};
  */
class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) return false;
            int n = 1;
            while (n <= x / 10) n = n * 10;
            for (int i = n; i > 1; i /= 100) {
                if (x % 10 != x / i) {
                    return false;
                }
                x %= i;
                x /= 10;
            }
            return true;
        }
};

