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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
         unordered_map<int, TreeNode*> tree_;
         int sz = descriptions.size();
         unordered_set<int> parentSet;
         unordered_set<int> childSet;
        for(int i = 0; i < sz; i++) {
             parentSet.insert(descriptions[i][0]);
             childSet.insert(descriptions[i][1]);
        }
         int rootvalue = -1;
        for(auto& node : parentSet) {
            if(childSet.find(node) == childSet.end()) {
                rootvalue = node;
                break;
            }
        }
        for(int i = 0; i < sz; i++) {
            TreeNode* parent;
            TreeNode* child;
            parentSet.insert(descriptions[i][0]);
            if(tree_.find(descriptions[i][0]) != tree_.end()) {
                parent = tree_[descriptions[i][0]];
            } else {
                parent = new TreeNode(descriptions[i][0]);
            }
           
            
             if(tree_.find(descriptions[i][1]) != tree_.end()) {
                child = tree_[descriptions[i][1]];
            } else {
                child = new TreeNode(descriptions[i][1]);
            }
            
            if(descriptions[i][2]) {
                parent->left = child;
            } else {
                parent->right = child;
            }
            tree_[descriptions[i][0]] = parent;
            tree_[descriptions[i][1]] = child;
        }
        return tree_[rootvalue];
    }
};