/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int& res, int dep) {
        if(!root) {
            return;
        }
        if(!root->left && !root->right) {
            res = min(res, dep);
            return;
        }
        dfs(root->left, res, dep+1);
        dfs(root->right, res, dep+1);
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int res = INT_MAX;
        dfs(root, res, 1);
        return res;
    }
};