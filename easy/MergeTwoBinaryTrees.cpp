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
    TreeNode* mv = NULL;

    TreeNode* merge(TreeNode* t1, TreeNode* t2) {
        int vall = (t1 == NULL) ? 0 : t1->val;
        int valr = (t2 == NULL) ? 0 : t2->val;
        TreeNode* curr = new TreeNode(vall + valr);
        if ((t1 != NULL && t1->left != NULL) ||
            (t2 != NULL && t2->left != NULL)) {
            curr->left =
                merge(t1 != NULL ? t1->left : t1, t2 != NULL ? t2->left : t2);
        }

        if ((t1 != NULL && t1->right != NULL) ||
            (t2 != NULL && t2->right != NULL)) {
            curr->right =
                merge(t1 != NULL ? t1->right : t1, t2 != NULL ? t2->right : t2);
        }

        return curr;
    }
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* rt = NULL;

        if (!(t1 == NULL && t2 == NULL)) {
            rt = merge(t1, t2);
        }
        return rt;
    }
};