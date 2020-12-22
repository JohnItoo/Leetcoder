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

    void recursivePreorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        result.push_back(root->val);
        recursivePreorder(root->left, result);
        recursivePreorder(root->right, result);
    }


    void iterativePreorder(TreeNode* root, vector<int>& result) {
        stack <TreeNode*> resultStack;
        if (root != NULL)  resultStack.push(root);
        while (!resultStack.empty()) {
            TreeNode* current = resultStack.top();
            resultStack.pop();

            result.push_back(current->val);
            if (current->right != NULL) {
                resultStack.push(current->right);
            }

            if (current->left != NULL) {
                resultStack.push(current->left);
            }
        }
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        recursivePreorder(root, result);
        return result;
    }
};