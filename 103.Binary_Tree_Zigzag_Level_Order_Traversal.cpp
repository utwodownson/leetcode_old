/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
 * 
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 * 
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * 
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    public:
        vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<vector<int> > ans;
            if (root == NULL) return ans;
            vector<int> num;
            queue<TreeNode *> st;
            int level, count = 1, flag = 0;
            st.push(root);
            while (!st.empty()) {
                level = 0;
                num.clear();

                for (int i = 0; i < count; ++i) {
                    root = st.front();
                    st.pop();
                    num.push_back(root->val);
                    if (root->left) {
                        st.push(root->left);
                        level++;
                    }
                    if (root->right) {
                        st.push(root->right);
                        level++;
                    }
                }
                count = level;
                if (flag)
                    reverse(num.begin(), num.end());
                ans.push_back(num);
                flag ^= 1;
            }
            return ans;
        }
};

