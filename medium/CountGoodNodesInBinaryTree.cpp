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
    void dfs(TreeNode* root, int& goodNodes, int& currentMax) {
        if (!root) {
            return;
        }
        if (root->val >= currentMax) {
            goodNodes++;
        }
        int newCurrentMax = max(currentMax, root->val);
        dfs(root->left, goodNodes, newCurrentMax);
        dfs(root->right, goodNodes, newCurrentMax);
    }
    int goodNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int goodNodes = 0;
        int currentMax = -1e5;

        dfs(root, goodNodes, currentMax);
        return goodNodes;
    }
};
