/* Given two words (start and end), and a dictionary, 
 * find the length of shortest transformation sequence from start to end, such that:
 * Only one letter can be changed at a time
 * Each intermediate word must exist in the dictionary
 * For example,
 * Given:
 * start = "hit"
 * end = "cog"
 * dict = ["hot","dot","dog","lot","log"]
 * As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * return its length 5.
 * Note:
 * Return 0 if there is no such transformation sequence.
 * All words have the same length.
 * All words contain only lowercase alphabetic characters.
 */
class Solution {
    public:
        int ladderLength(string start, string end, unordered_set<string> &dict) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            if (start == end) return 1;

            map<string, int> hash;
            queue<string> q;
            q.push(start);
            hash[start] = 0;

            while (!q.empty()) {
                string now = q.front(); q.pop();
                for (int i = 0; i < now.size(); ++i) {
                    for (char c = 'a'; c <= 'z'; ++c) {
                        string next = now;
                        next[i] = c;
                        if (next == end) return hash[now] + 2;
                        if (dict.find(next) != dict.end() && hash.find(next) == hash.end()) {
                            hash[next] = hash[now] + 1;
                            q.push(next);
                        }
                    }
                }
            }

            return 0;
        }
};
