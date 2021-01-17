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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, 0, inorder.size() - 1, preorder, inorder);
    }

   private:
    TreeNode* build(int preorderStart, int inorderStart, int inorderEnd,
                    vector<int>& preorder, vector<int>& inorder) {
        if (preorderStart >= preorder.size() || inorderStart > inorderEnd)
            return NULL;
        TreeNode* root = new TreeNode(preorder[preorderStart]);
        int inorderIdx = 0;
        for (int i = inorderStart; i <= inorderEnd; i++) {
            if (root->val == inorder[i]) {
                inorderIdx = i;
            }
        }
        // preorder visits immediate left next so preorderStart + 1;
        root->left = build(preorderStart + 1, inorderStart, inorderIdx - 1,
                           preorder, inorder);
        // the immediate right is after all the nodes in the left subtree
        // this is found from the inorder array.
        int numOfNodesInLeft = inorderIdx - inorderStart;
        root->right = build(preorderStart + numOfNodesInLeft + 1,
                            inorderIdx + 1, inorderEnd, preorder, inorder);
        return root;
    }
};