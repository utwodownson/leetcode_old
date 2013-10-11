/* Given two sorted integer arrays A and B, merge B into A as one sorted array.
 * Note:
 * You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */
class Solution {
    public:
        void merge(int A[], int m, int B[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int i = m - 1, j = n - 1;
            while (i >= 0 && j >= 0) {
                if (A[i] < B[j]) 
                    A[i + j + 1] = B[j--];
                else
                    A[i + j + 1] = A[i--];
            }
            while (j >= 0) A[j] = B[j--]; 
        }
};
