/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   public:
    void undirectedEdges(TreeNode* parent, TreeNode* current,
                         vector<vector<int> >& adj) {
        if (!current) return;
        if (parent) {
            int pval = parent->val;
            int cval = current->val;
            adj[pval].push_back(cval);
            adj[cval].push_back(pval);
        }
        undirectedEdges(current, current->left, adj);
        undirectedEdges(current, current->right, adj);
    }
    void treeToGraph(TreeNode* root, vector<vector<int> >& adj) {
        undirectedEdges(NULL, root, adj);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<vector<int> > adj(505, vector<int>());
        treeToGraph(root, adj);
        queue<pair<int, int> > q;
        q.push({target->val, 0});
        unordered_map<int, int> done;
        vector<int> result;

        while (!q.empty()) {
            pair<int, int> top = q.front();
            q.pop();
            if (done.count(top.first)) continue;
            done[top.first] = 1;
            if (top.second == k) {
                result.push_back(top.first);
            }
            for (int edges : adj[top.first]) {
                pair<int, int> add = {edges, top.second + 1};
                q.push(add);
            }
        }
        return result;
    }
};