/* Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers = { 2, 7, 11, 15 }, target = 9
 * Output: index1 = 1, index2 = 2
 */

typedef struct _Node {
    int val;
    int index;
    _Node(){} //
    _Node(int v, int idx) : val(v), index(idx){} //
}Node;

bool cmp(const Node &left, const Node &right) { //
    return left.val < right.val;
}

class Solution {
    public:
        vector<int> twoSum(vector<int> &numbers, int target) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<Node> list;
            for (int i = 0 ; i < numbers.size(); ++i)  // size() list
                list.push_back(Node(numbers[i], i + 1)); // push_back

            sort(list.begin(), list.end(), cmp); // sort

            vector<int> ret;
            int i = 0, j = numbers.size() - 1;
            while (i < j) {
                int sum = list[i].val + list[j].val;
                if (sum < target) ++i;
                else if (target < sum) --j;
                else {
                    int mini = min(list[i].index, list[j].index); // min
                    int maxj = max(list[i].index, list[j].index); // max
                    ret.push_back(mini);
                    ret.push_back(maxj);
                    return ret;
                }
            }
        }
};
