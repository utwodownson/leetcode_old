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
            unordered_map<int, int> hashmap;
            for (int i = 0; i < num.size(); ++i)
                hashmap[num[i]] = i;
            vector<int> visited(num.size(), 0);
            int maxV = INT_MIN;
            for (int i = 0; i < num.size(); ++i) {
                if (visited[i] == 1) continue;
                visited[i] = 1;
                int len = 1;
                int index = num[i] - 1;
                while (hashmap.find(index) != hashmap.end()) {
                    visited[hashmap[index]] = 1;
                    index--;
                    len++;
                }

                index = num[i] + 1;
                while (hashmap.find(index) != hashmap.end()) {
                    visited[hashmap[index]] = 1;
                    index++;
                    len++;
                }
                if (len > maxV)
                    maxV = len;
            }
            return maxV;
        }
};
