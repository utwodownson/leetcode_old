/* Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * Note:
 * You may assume that A has enough space to hold additional elements from B. 
 * The number of elements initialized in A and B are m and n respectively.
 */
class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            for (int i = m - 1, j = n - 1, len = m + n; j >= 0; --len) 
                A[len - 1] = (i >= 0 && A[i] > B[j]) ? A[i--] : B[j--];
        }
};
