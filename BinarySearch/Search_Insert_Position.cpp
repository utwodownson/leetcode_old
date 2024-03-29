/*
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */
class Solution {
    public:
        int searchInsert(int A[], int n, int target) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int low = 0, high = n, mid = 0;
            while (low < high) 
                (target < A[mid = (low + high) >> 1]) ? high = mid : low = mid + 1;
            return (target == A[low - 1]) ? low - 1 : low;
        }
};
