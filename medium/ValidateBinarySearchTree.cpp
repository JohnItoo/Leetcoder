/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 right(right) {}
 * };
 [5,4,6,null,null,3,7]
 -2147483648

 */
class Solution {
   public:
    int mx = -INT_MAX;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool left = isValidBST(root->left);
        if (mx != -INT_MAX && root->val <= mx) return false;
        mx = root->val;

        bool right = isValidBST(root->right);

        return left && right;
    }
};