/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
 * Find all unique triplets in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
 * The solution set must not contain duplicate triplets.
 *      For example, given array S = { -1 0 1 2 -1 -4 },
 * 
 *            A solution set is:
 *                (-1, 0, 1)
 *                (-1, -1, 2)
 */
class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            sort(num.begin(), num.end());
            int len = num.size();
            int target = 0;
            vector<vector<int>> ans;
            vector<int> tmp;
            for (int i = 0; i < len; ++i) {
                target = -num[i];
                if (i > 0 && num[i] == num[i - 1]) continue;
                for (int left = i + 1, right = len - 1; left < right; )  {
                    if (num[left] + num[right] < target) 
                        left++;
                    else if (num[left] + num[right] > target)
                        right--;
                    else {
                        tmp.clear();
                        tmp.push_back(num[i]);
                        tmp.push_back(num[left]);
                        tmp.push_back(num[right]);
                        ans.push_back(tmp);
                        do {
                            left++;
                        } while (left < right && num[left] == num[left - 1]);
                        do {
                            right--;
                        } while (left < right && num[right] == num[right + 1]);
                    }
                }
            }
            return ans;
        }
};
