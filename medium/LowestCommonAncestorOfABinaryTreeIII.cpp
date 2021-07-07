/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        if(!p && !q) return p;
        if(!p) return p;
        if(!q) return q;
        if(p == q) return q;
        unordered_set<Node*> visited;
        while(p) {
           visited.insert(p);
            p = p->parent;
        }
        
        while(q) {
            if(visited.find(q) != visited.end()) {
                return q;
            }
            q = q->parent;
        }
        return NULL;
    }
};