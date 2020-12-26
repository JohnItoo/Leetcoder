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
    TreeNode *findLeftestNodeFromRight(TreeNode *root, int key)
    {
        while (root != NULL && root->left != NULL)
            root = root->left;
        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {

        if (root == NULL)
        {
            return root;
        }

        if (root->val == key)
        {
            TreeNode *leastGreatestNode = findLeftestNodeFromRight(root->right, key);

            if (leastGreatestNode == NULL)
            {
                return root->left;
            }
            else
            {
                cout << leastGreatestNode->val << endl;
                leastGreatestNode->left = root->left;
                return root->right;
            }
        }

        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else
        {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};