/* Given n, generate all structurally unique BST's (binary search trees) that store values 1...n. */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/* Given n, generate all structurally unique BST's (binary search trees) that store values 1...n. */
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
    vector<TreeNode *> generate(int start, int end) {
        vector<TreeNode *> subTree;
        if (start > end) {
            subTree.push_back(NULL);
            return subTree;
        }
        for (int k = start; k <= end; ++k) {
            vector<TreeNode *> leftsubs = generate(start, k - 1);
            vector<TreeNode *> rightsubs = generate(k + 1, end);
            for (int i = 0; i < leftsubs.size(); ++i) {
                for (int j = 0; j < rightsubs.size(); ++j) {
                    TreeNode *root = new TreeNode(k);
                    root->left = leftsubs[i];
                    root->right = rightsubs[j];
                    subTree.push_back(root);
                }
            }
        }
        return subTree;
    }
    public:
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!n) return generate(1, 0);
        return generate(1, n);
    }
};
