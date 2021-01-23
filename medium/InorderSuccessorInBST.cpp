/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* prev = NULL;
        TreeNode* result = NULL;
        helper(root, &prev, &result, p);
        return result;
    }

    void helper(TreeNode* root, TreeNode** prev, TreeNode** result,
                TreeNode* p) {
        if (!root) return;

        helper(root->left, prev, result, p);
        if ((*prev) && (*prev)->val == p->val) {
            (*result) = root;
        }
        (*prev) = root;

        helper(root->right, prev, result, p);
    }
};