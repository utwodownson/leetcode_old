/* Determine whether an integer is a palindrome. Do this without extra space.
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * If you are thinking of converting the integer to string, 
 * note the restriction of using extra space.
 * You could also try reversing an integer. However, 
 * if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
 * How would you handle such case?
 * There is a more generic way of solving this problem.
 */
class Solution {
    public:
        bool isPalindrome(int x) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if (x < 0) return false;
            int num = x, bit = 1;
            while (bit <= x / 10) bit *= 10;
            while (num > 9) {
                if (num / bit != num % 10) return false;
                num %= bit;
                num /= 10;
                bit /= 100;
            }
            return true;
        }
};
