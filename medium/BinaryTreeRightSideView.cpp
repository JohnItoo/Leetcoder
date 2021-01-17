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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        queue<pair<TreeNode*, int> > q;
        if (!root) return result;
        q.push(make_pair(root, 0));
        int prev = -1;
        while (!q.empty()) {
            pair<TreeNode*, int> ft = q.front();
            q.pop();
            int level = ft.second;
            TreeNode* node = ft.first;

            if (level != prev) {
                prev = level;
                result.push_back(node->val);
            }
            if (node->right) {
                q.push(make_pair(node->right, level + 1));
            }
            if (node->left) {
                q.push(make_pair(node->left, level + 1));
            }
        }
        return result;
    }
};