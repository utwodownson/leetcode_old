/* Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 * For example,
 * [1,1,2] have the following unique permutations:
 * [1,1,2], [1,2,1], and [2,1,1].
 */
class Solution {
    void Generate(vector<int> &num, int step, vector<bool> &visited, vector<int> &solution,
            vector<vector<int> > &ret) {
        if (step >= num.size()) {
            ret.push_back(solution);
            return;
        }
        for (int i = 0; i < num.size(); ++i) {
            if (!visited[i]) {
                visited[i] = true;
                solution.push_back(num[i]);
                Generate(num, step + 1, visited, solution, ret);
                solution.pop_back();
                visited[i] = false;
            }
        }
    }
    public:
    vector<vector<int> > permute(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        vector<vector<int> > ret;
        vector<int> solution;
        vector<bool> visited(num.size(), false);

        if (num.size() == 0) return ret;

        Generate(num, 0, visited, solution, ret);

        return ret;
    }
};

