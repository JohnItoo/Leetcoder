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
    int answer;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        answer = max(answer, left + right + root->val);
        return max(0, root->val + max(left, right)); // max 0 incase the path is better off without the path under it eg 2 and the left child is -1
    }
    int maxPathSum(TreeNode* root) {
        answer = INT_MIN;
        dfs(root);
        return answer;
    }
};