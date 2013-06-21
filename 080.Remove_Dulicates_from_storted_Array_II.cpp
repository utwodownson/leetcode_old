class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int i = 0, num = 0;
            sort(A, A + n);
            while (i < n) {
                int tmp = A[i++];
                A[num++] = tmp;
                if (i >= n) break;
                if (A[i] == tmp) A[num++] = tmp;
                while (A[i] == tmp) ++i;
            }
            return num;
        }
};
