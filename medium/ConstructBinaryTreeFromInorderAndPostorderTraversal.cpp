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
    TreeNode* recur(int postorderStart, int inorderStart, int inorderEnd,
                    vector<int>& inorder, vector<int>& postorder) {
        if (inorderStart > inorderEnd || postorderStart < 0) {
            return NULL;
        }
        int n = inorder.size();
        int idx = -1;
        for (int i = 0; i < n; i++) {
            if (inorder[i] == postorder[postorderStart]) {
                idx = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(postorder[postorderStart]);
        root->right =
            recur(postorderStart - 1, idx + 1, inorderEnd, inorder, postorder);
        int numsRight = inorderEnd - idx;
        root->left = recur(postorderStart - numsRight - 1, inorderStart,
                           idx - 1, inorder, postorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        TreeNode* res = recur(n - 1, 0, n - 1, inorder, postorder);
        return res;
    }
};