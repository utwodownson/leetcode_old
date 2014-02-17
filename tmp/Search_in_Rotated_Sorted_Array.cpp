/* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 * You are given a target value to search. If found in the array return its index, otherwise return -1.
 * You may assume no duplicate exists in the array.
 */
class Solution {
    public:
        int search(int A[], int n, int target) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int low = 0, high = n;
            while (low < high) {
                int mid = (low + high) >> 1;
                if (A[mid] == target) return mid;
                if (A[low] < A[mid]) 
                    (target < A[mid] && A[low] <= target) ? high = mid : low = mid + 1;
                else 
                    (target > A[mid] && target <= A[high - 1]) ? low = mid + 1 : high = mid;
            }
            return -1;
        }
};
