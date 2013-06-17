class Solution {
    public:
        double findMedianSortedArrays(int A[], int m, int B[], int n) {
                    // Start typing your C/C++ solution below
                    // DO NOT write int main() function

                    int *C = (int *) malloc(sizeof(int) * (m + n));
                    int i = 0, left = 0, right = 0;
                    while (i < (m + n) && left < m && right < n) 
                        C[i++] = A[left] > B[right] ? B[right++] : A[left++];
                    while (left < m)
                        C[i++] = A[left++];
                    while (right < n)
                        C[i++] = B[right++];
                    int mid = m - (m - n) / 2;
                    return C[mid];
        }
};
