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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool hasSeen = false;
        int sum = 0;
        if (!root) return false;
        dfs(root, targetSum, hasSeen, sum);
        return hasSeen;
    }
    void dfs(TreeNode* root, int targetSum, bool& hasSeen, int& sum) {
        if (!root) return;
        sum += root->val;

        if (!root->left && !root->right) {
            cout << sum << endl;
            hasSeen |= (targetSum == sum);
        }
        dfs(root->left, targetSum, hasSeen, sum);
        dfs(root->right, targetSum, hasSeen, sum);
        sum -= root->val;
    }

   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return path(root, targetSum);
    }
    bool path(TreeNode* root, int rem) {
        if (!root->left && !root->right) {
            return root->val == rem;
        }
        bool left = false;
        int newrem = rem - root->val;
        if (root->left) {
            left = path(root->left, newrem);
        }
        bool right = false;
        if (root->right) {
            right = path(root->right, newrem);
        }
        return left || right;
    }
};
