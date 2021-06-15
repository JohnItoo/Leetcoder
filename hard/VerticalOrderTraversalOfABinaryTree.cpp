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
struct Item {
    TreeNode* val;
    int row;
    int col;
    Item(TreeNode* v, int r, int c) : val(v), row(r), col(c) {}
};
class Solution {

public:
    static bool comp(Item* it1, Item* it2) {
        if(it1->row == it2->row) {
            return it1->val->val < it2->val->val;
        }
    
        return it1->row < it2->row;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<Item*> q;
        map<int, vector<Item*> > mp;
        Item* it = new Item(root, 0, 0);
        q.push(it);
        
        while(!q.empty()) {
            Item* top = q.front(); q.pop();
            TreeNode* curr = top->val;
            mp[top->col].push_back(top);
            if(curr->left) {
                Item* left = new Item(curr->left, top->row+1, top->col-1);
                q.push(left);
            }
            if(curr->right) {
                Item* right = new Item(curr->right, top->row +1, top->col+1);
                q.push(right);
            }
        }
        vector<vector<int> > result;
        for(auto hh : mp) {
            vector<Item*> here = hh.second;
            sort(here.begin(), here.end(), comp);

            vector<int> res;
            for(Item* itt : here) {
                res.push_back(itt->val->val);
            }
      
            result.push_back(res);
        }
        return result;
       
    }
};