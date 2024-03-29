/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (A[j] != elem) 
                A[i++] = A[j];
        }
        return i;
    }
};
