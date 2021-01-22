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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int n = pre.size();
        if (n == 0) return NULL;
        TreeNode* result = helper(pre, post, 0, n - 1);
        return result;
    }

    TreeNode* helper(vector<int>& pre, vector<int>& post, int start, int end) {
        if (start > end) return NULL;
        TreeNode* root = new TreeNode(pre[start]);
        if (start == end) return root;

        int postIdx = -1;
        int n = post.size();
        for (int i = 0; i < n; i++) {
            if (post[i] == pre[start]) {
                postIdx = i;
                break;
            }
        }

        int leftBorder = -1;

        for (int i = 0; i < n; i++) {
            if (pre[i] == post[postIdx - 1]) {
                leftBorder = i - 1;
                break;
            }
        }

        root->left = helper(pre, post, start + 1, leftBorder);
        root->right = helper(pre, post, leftBorder + 1, end);

        return root;
    }
};