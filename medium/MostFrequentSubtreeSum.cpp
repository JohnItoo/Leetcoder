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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;
        vector<int> result;
        treeSum(root, freq);
        priority_queue<pair<int, int> > items;
        for (auto occurrence : freq) {
            pair<int, int> current =
                make_pair(occurrence.second, occurrence.first);
            items.push(current);
        }
        if (items.size() == 0) return result;
        pair<int, int> mostOccurrent = items.top();
        items.pop();
        result.push_back(mostOccurrent.second);
        while (items.size() != 0 &&
               (items.top()).first == mostOccurrent.first) {
            pair<int, int> currentOccurrent = items.top();
            items.pop();
            result.push_back(currentOccurrent.second);
        }

        return result;
    }
    int treeSum(TreeNode* root, unordered_map<int, int>& freq) {
        if (!root) return 0;
        int totalFromRoot =
            root->val + treeSum(root->left, freq) + treeSum(root->right, freq);
        freq[totalFromRoot]++;
        return totalFromRoot;
    }
};