/**
 * Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 *
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 *
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i = 0, j = 0;
            while (j < n) {
                if (i < 2 || A[i - 2] != A[j] || A[j - 1] != A[j]) {
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

/*
int i = 0, j = 1;
while (j < n) {
    if (A[i] != A[j]) 
        A[++i] = A[j];
    else if (A[j - 1] == A[j] && i % 2 == 0) 
        A[++i] = A[j];
    ++j;
}
return (i + 1);
*/
