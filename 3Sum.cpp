/* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 */
class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            sort(num.begin(), num.end());
            vector<vector<int> > ans;
            vector<int> tmp(3);
            if (num.size() < 3) return ans;

            for (int i = 0; i < num.size(); ) {
                for (int j = i + 1; j < num.size(); ) {
                    int target = 0 - (num[i] + num[j]);
                    int low = j + 1, high = num.size(), mid;
                    while (low < high) 
                        (target < num[mid = (low + high) >> 1]) ? high = mid : low = mid + 1;
                    if (low - 1 > j && target == num[low - 1]) {
                        tmp[0] = num[i];
                        tmp[1] = num[j];
                        tmp[2] = num[low - 1];
                        ans.push_back(tmp);
                    }
                    while (++j < num.size() && num[j - 1] == num[j]);
                }
                while (++i < num.size() && num[i - 1] == num[i]);
            }
            return ans;
        }
};
