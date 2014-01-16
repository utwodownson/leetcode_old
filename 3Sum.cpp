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

            for (int i = 0; i < num.size(); ++i) {
                int sum = -num[i];
                for (int j = i + 1;
                int target = sum - num[i + 1]; 
                if (i > 0 && num[i - 1] == num[i]) continue;
                while (low <= high) {
                    int sum = num[low] + num[high];
                    if (sum == target) {
                        tmp[0] = -target;
                        tmp[1] = num[low];
                        tmp[2] = num[high];
                        ans.push_back(tmp);
                        for (++low; low < high && num[low - 1] == num[low]; ++low);
                        for (--high; low < high && num[high] == num[high + 1]; --high);
                    } else if (sum < target) ++low;
                    else --high;
                }
            }
            return ans;
        }
};
