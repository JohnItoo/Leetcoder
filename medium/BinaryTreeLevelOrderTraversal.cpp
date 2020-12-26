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
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        if (root != NULL)
            q.push(make_pair(root, 1));
        vector<vector<int>> result;
        while (!q.empty())
        {
            pair<TreeNode *, int> front = q.front();
            q.pop();
            TreeNode *node = front.first;
            int parentDepth = front.second;
            if (result.size() < parentDepth)
            {
                vector<int> curr;
                result.push_back(curr);
            }
            result[result.size() - 1].push_back(node->val);
            if (node->left != NULL)
                q.push(make_pair(node->left, parentDepth + 1));
            if (node->right != NULL)
                q.push(make_pair(node->right, parentDepth + 1));
        }
        return result;
    }
};