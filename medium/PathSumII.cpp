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
    void checkTreeForTarget(TreeNode* root, int& targetSum, vector<vector<int> >& result, vector<int>& curr, int& currSum) {
        if(!root) return;
        if(!root->left && !root->right) {
            currSum += root->val;
            curr.push_back(root->val);
            if(targetSum == currSum) {
                
                result.push_back(curr);
            }
            currSum -= root->val;
            curr.pop_back();
            return;
        }
        curr.push_back(root->val);
        int newSum = currSum + root->val;
        checkTreeForTarget(root->left, targetSum, result, curr, newSum);
        checkTreeForTarget(root->right, targetSum, result, curr, newSum);
        curr.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > result;
        vector<int> curr;
        int currSum = 0;
        checkTreeForTarget(root, targetSum, result,curr, currSum);
        return result;
    }
};