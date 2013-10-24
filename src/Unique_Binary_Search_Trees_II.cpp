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
    vector<TreeNode *> *generate(int left, int right) {
        vector<TreeNode *> *subTree = new vector<TreeNode*>();
        if (left > right) {
            subTree->push_back(NULL);
            return subTree;
        }
        for (int i = left; i <= right; ++i) {
            vector<TreeNode*> *leftSubs = generate(left, i - 1);
            vector<TreeNode*> *rightSubs = generate(i + 1, right);
            for(int j = 0; j < leftSubs->size(); j++) {
                for(int k = 0; k < rightSubs->size(); k++) {
                    TreeNode *node = new TreeNode(i); 
                    node->left = (*leftSubs)[j]; 
                    node->right = (*rightSubs)[k];
                    subTree->push_back(node); 
                }
            }
        }
        return subTree;
    }
    public:
    vector<TreeNode *> generateTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0) return *generate(1, 0);
        return *generate(1, n);
    }
};

