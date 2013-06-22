class Solution {
    public:
        int removeDuplicates(int A[], int n) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            int len = n, num = 0, i = 0;
            sort(A, A + len);
            while (i < len) {
                int tmp = A[i];
                while (A[i] == tmp) A[i++] = 0; 
                A[num++] = tmp;
            }
            return num;
        }
};
