/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        int currLevel = -1;
        queue<pair<Node*, int> > levelQueue;
        vector<vector<int>> res;
        vector<int> curr;
        if(!root) return res;
        levelQueue.push({root, 1});
        
        while(!levelQueue.empty()) {
            pair<Node*, int> currNode = levelQueue.front();
            levelQueue.pop();
            if(currNode.second != currLevel) {
                if(currLevel != -1) {
                    vector<int> newV;
                    res.push_back(curr);
                    curr = newV;
                }
                currLevel = currNode.second;
            }
            curr.push_back(currNode.first->val);
            
            for(Node* child : (currNode.first)->children) {
                levelQueue.push({child, currNode.second+1});
            }
        }
        res.push_back(curr);
        return res;
    }
};