/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 * 
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 *
 * Note: Recursive solution is trivial, could you do it iteratively?
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
        vector<int> inorderTraversal(TreeNode *root) {
            // Start typing your C/C++ solution below
            // DO NOT write int main() function
            vector<int> ans;
            vector<TreeNode *> st;
            for ( ; ; ) {
                while (root) {
                    st.push_back(root);
                    root = root->left;
                }
                if (st.size() == 0) break;
                root = st.back();
                ans.push_back(root->val);
                st.pop_back();
                root = root->right;
            }
            return ans;
        }
};
