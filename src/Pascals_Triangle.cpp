/* Given numRows, generate the first numRows of Pascal's triangle.
 * For example, given numRows = 5,
 * Return
 * [
        [1],
       [1,1],
      [1,2,1],
     [1,3,3,1],
    [1,4,6,4,1]
   ]
 */
class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            // Note: The Solution object is instantiated only once and is reused by each test case.
            vector<vector<int>> ans;
            vector<int> row;
            for (int i = 0; i < numRows; ++i) {
                for (int c = i - 1; c > 0; --c) 
                    row[c] += row[c - 1];
                row.push_back(1);
                ans.push_back(row);
            }
            return ans;
        }
};
