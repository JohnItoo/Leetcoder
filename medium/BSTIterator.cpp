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
class BSTIterator {
public:
    queue<int> arriveQ;
    BSTIterator(TreeNode* root) {
        inOrderTraversal(root);
    }
    
    int next() {
        int front = arriveQ.front(); 
        arriveQ.pop();
        return front;
    }
    
    bool hasNext() {
        return arriveQ.size() > 0;
    }
    
private:
    void inOrderTraversal(TreeNode* root) {
        if(!root) return;
        inOrderTraversal(root->left);
        arriveQ.push(root->val);
        inOrderTraversal(root->right);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */