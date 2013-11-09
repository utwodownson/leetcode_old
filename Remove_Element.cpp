/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int i = 0;
        while (i < n) {
            while (i < n && A[n - 1] == elem) --n;
                if (i < n && A[i] == elem)
                    A[i++] = A[--n];
                else
                    i++;
        }
        return n;
    }
};
