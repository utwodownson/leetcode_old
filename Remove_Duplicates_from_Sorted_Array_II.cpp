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
            int index = 0;
            for (int i = 0; i < n; ++i) {
                if (i > 0 && i < n - 1 && A[i - 1] == A[i] && A[i] == A[i + 1]) continue;
                A[index++] = A[i];
            }
            return index;
        }
};
