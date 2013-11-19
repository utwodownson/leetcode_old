/* Given a collection of numbers, return all possible permutations.
 * For example,
 * [1,2,3] have the following permutations:
 * [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */
class Solution {
        void Generate(vector<int> &num, int step, vector<int> &visited, vector<int> &solution,
            vector<vector<int> > &ret) {
            if (step == num.size()) {
                ret.push_back(solution);
                return;
            }
            for (int i = 0; i < num.size(); ++i) {
                if (visited[i] == 0) {
                    visited[i] = 1;
                    solution.push_back(num[i]);
                    Generate(num, step + 1, visited, solution, ret);
                    solution.pop_back();
                    visited[i] = 0;
                }
            }
        }
    public:
        vector<vector<int> > permute(vector<int> &num) {
            // IMPORTANT: Please reset any member data you declared, as
            // the same Solution instance will be reused for each test case.
            vector<vector<int> > ret;
            vector<int> solution;
            vector<int> visited(num.size(), 0);

            if (num.size() == 0) return ret;

            Generate(num, 0, visited, solution, ret);

            return ret;
        }
};
