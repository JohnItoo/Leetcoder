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
    void dfs(TreeNode* root, int& sum, int current) {
        current = (current * 10) + root->val;

        if (!root->left && !root->right) {
            cout << current << endl;
            sum += current;
            return;
        }
        if (root->left) dfs(root->left, sum, current);
        if (root->right) dfs(root->right, sum, current);
    }
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return root->val;
        int sum = 0;
        dfs(root, sum, 0);
        return sum;
    }
};