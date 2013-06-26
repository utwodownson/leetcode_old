/**
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
 * 
 * Do not allocate extra space for another array, you must do this in place with constant memory.
 * 
 * For example,
 * Given input array A = [1,1,2],
 * 
 * Your function should return length = 2, and A is now [1,2]. 
 */

class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i = 0, j = 0;
            while (j < n) {
                if (j == 0 || A[j] != A[j - 1]) {
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
 * second time

int i = 0, j = 1;
if (n < 2) return n;
while (j < n) {
    if (A[j] != A[i])
        A[++i] = A[j];
    ++j;
}
return (i + 1);
