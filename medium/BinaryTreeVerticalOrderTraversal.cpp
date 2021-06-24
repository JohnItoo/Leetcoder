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
    static bool comp(pair<int, int> p1, pair<int, int> p2) {
       return p1.first < p2.first;
    }
    void dfs(map<int, vector<pair<int, int> >>& coords, TreeNode* root, int r, int c) {
        if(!root) return;
        coords[c].push_back({r, root->val});
        dfs(coords, root->left, r+1, c-1);
        dfs(coords, root->right, r+1, c+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<pair<int, int> > > coordinates;
        dfs(coordinates, root, 0, 0);
        vector<vector<int> > result;
        for(auto values : coordinates) {
            vector<pair<int, int> >current = values.second;
            sort(current.begin(), current.end(), comp);
            vector<int> add;
            for(auto value : current) {
                add.push_back(value.second);
            }
            result.push_back(add);
        }
        return result;
    }
};