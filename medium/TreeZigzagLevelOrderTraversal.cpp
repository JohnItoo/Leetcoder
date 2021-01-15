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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;

        map<int, vector<int>> mp;

        queue<pair<TreeNode*, int>> q;

        if (root == NULL) return result;

        q.push(make_pair(root, 1));

        unordered_map<TreeNode*, int> visited;
        while (!q.empty()) {
            pair<TreeNode*, int> top = q.front();
            q.pop();

            TreeNode* node = top.first;

            if (visited.count(node)) continue;

            visited[node] = 1;

            (mp[top.second]).push_back(node->val);

            if (node->left != NULL) {
                q.push(make_pair(node->left, top.second + 1));
            }
            if (node->right != NULL) {
                q.push(make_pair(node->right, top.second + 1));
            }
        }

        for (auto it : mp) {
            int level = it.first;
            vector<int> items = it.second;
            if (level % 2 == 0) {
                reverse(items.begin(), items.end());
            }
            result.push_back(items);
        }
        return result;
    }
};