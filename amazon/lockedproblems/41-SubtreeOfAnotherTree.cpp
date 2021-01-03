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
    bool check(TreeNode* first, TreeNode* second) {
        if(first == NULL && second == NULL) return true;
        if(first == NULL || second == NULL) return false;
        
        return (first->val == second->val ) && check(first->left, second->left) && check(first->right, second->right);
    }
    bool isSubtree(TreeNode* s, TreeNode* t) {
      if(check(s, t)) return true;
      if(s == NULL) return false;
      return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};