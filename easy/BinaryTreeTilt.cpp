/**
 * Definition for a binary tree node.
 * struct TreeNode {e
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
    int sumSub(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        return sumSub(root->left) + root->val + sumSub(root->right);
    }
    int findTilt(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lef = sumSub(root->left);
        int rig = sumSub(root->right);
        int diff = abs(lef - rig);
        return diff + findTilt(root->left) + findTilt(root->right);
    }
};