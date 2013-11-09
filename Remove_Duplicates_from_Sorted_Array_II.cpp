/* Follow up for "Remove Duplicates":
 * What if duplicates are allowed at most twice?
 * For example,
 * Given sorted array A = [1,1,1,2,2,3],
 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */
class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int i = 0, j = 0;
            while (j < n) {
                A[i++] = A[j++];
                while (j < n - 1 && A[j] == A[j - 1] && A[j] == A[j + 1]) j++;
                if (A[j] == A[j - 1] && j < n - 1) 
                    A[i++] = A[j++];
            }
            return i;
        }
};
