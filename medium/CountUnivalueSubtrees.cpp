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
    bool isUniValTree(TreeNode* root) {
        if (!root) return true;
        bool isSameAsLeft = true;
        if (root->left) {
            isSameAsLeft = root->val == root->left->val;
        }
        bool isSameAsRt = true;
        if (root->right) {
            isSameAsRt = root->val == root->right->val;
        }
        return isSameAsLeft && isSameAsRt && isUniValTree(root->left) &&
               isUniValTree(root->right);
    }
    void traverse(TreeNode* root, int& ans) {
        if (!root) return;
        if (isUniValTree(root)) {
            ans++;
        }
        traverse(root->left, ans);
        traverse(root->right, ans);
    }
    int countUnivalSubtrees(TreeNode* root) {
        int ans = 0;
        traverse(root, ans);
        return ans;
    }
};