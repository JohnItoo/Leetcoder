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
    void dfs(TreeNode* root, int& ans, TreeNode* parent) {
        if(!root) return;
        dfs(root->left, ans,root);
        dfs(root->right, ans,root);
        
        bool leftKidCovered = !root->left || root->left->val == 1;
        bool rightKidCovered = !root->right || root->right->val == 1;
        
        if((!parent && root->val == 0) || (!leftKidCovered || !rightKidCovered)) {
            ans++;
            root->val = 1;
            if(parent) {
                parent->val = 1;
            }
            if(root->left) {
                root->left->val = 1;
            }
            if(root->right) {
                root->right->val = 1;
            }
            
        }
    }
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        dfs(root, ans, NULL);
        return ans;
    }
};