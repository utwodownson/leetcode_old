/* There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)).
 */
class Solution {
    static double findK(int A[], int m, int B[], int n, int k) {
        if (n < m) return findK(B, n, A, m, k);
        if (m == 0) return B[k - 1];
        if (k == 1) return min(A[0], B[0]);

        int pa = min(k / 2, m), pb = k - pa;
        if (A[pa - 1] < B[pb - 1]) return findK(A + pa, m - pa, B, n, k - pa);
        else if (A[pa - 1] > B[pb - 1]) return findK(A, m, B + pb, n - pb, k - pb);
        else return A[pa - 1];
    }
    public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int ka = (m + n + 1) / 2, kb = (m + n) / 2 + 1;
            return (findK(A, m, B, n, ka) + findK(A, m, B, n, kb)) / 2.0; 
        }
};
