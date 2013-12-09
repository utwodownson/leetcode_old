/* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 */
class Solution {
    public:
        int longestConsecutive(vector<int> &num) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            unordered_map<int, bool> used;
            for (int i = 0; i < num.size(); ++i) used[num[i]] = false;

            int ans = 0;
            for (int i = 0; i < num.size(); ++i) {
                if (used[num[i]]) continue;
                int len = 1;
                used[num[i]] = true;
                for (int j = num[i] + 1; used.find(j) != used.end(); ++j) {
                    used[j] = true;
                    ++len;
                }
                for (int j = num[i] - 1; used.find(j) != used.end(); --j) {
                    used[j] = true;
                    ++len;
                }
                ans = max(ans, len);
            }
            return ans;
        }
};
