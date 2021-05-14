/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    void preorderTraversal(vector<int>& preorder, TreeNode* root) {
        if (!root) return;
        preorder.push_back(root->val);
        preorderTraversal(preorder, root->left);
        preorderTraversal(preorder, root->right);
    }
    void flatten(TreeNode* root) {
        vector<int> preorder;
        preorderTraversal(preorder, root);
        int n = preorder.size();
        if (n <= 0) return;
        TreeNode* travs = root;
        for (int i = 0; i < n; i++) {
            travs->left = NULL;
            travs->val = preorder[i];
            if (i + 1 < n && travs->right == NULL) {
                travs->right = new TreeNode();
            }
            travs = travs->right;
        }
    }
};