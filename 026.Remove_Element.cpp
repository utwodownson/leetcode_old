/**
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * 
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

class Solution {
    public:
        int removeElement(int A[], int n, int elem) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i = 0, j = 0;
            while (j < n) {
                if (A[j] != elem) {
                    if (i < j) {
                        A[i] = A[j];
                    } 
                    ++i;
                }
                ++j;
            }
            return i;
        }
};
