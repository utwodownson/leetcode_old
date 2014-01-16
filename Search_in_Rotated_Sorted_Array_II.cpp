/* Follow up for "Search in Rotated Sorted Array":
 * What if duplicates are allowed?
 * Would this affect the run-time complexity? How and why?
 * Write a function to determine if a given target is in the array.
 */
class Solution {
    public:
        bool search(int A[], int n, int target) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            int low = 0, high = n;
            while (low < high) {
                int mid = (low + high) >> 1;
                if (A[mid] == target) return true;
                if (A[low] < A[mid]) 
                    (target < A[mid] && A[low] <= target) ? high = mid : low = mid + 1;
                else if (A[low] > A[mid])
                    (target > A[mid] && target <= A[high - 1]) ? low = mid + 1 : high = mid;
                else
                    ++low;
            }
            return false;
        }
};
