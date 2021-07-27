/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    Node* head = NULL;
    Node* tail = NULL;
   void inOrder(Node* root) {
        if(!root) return;
        inOrder(root->left);
        
       if(!head) {
           head = root;
           tail = root;
       }else {
           root->left = tail;
           tail->right = root;
           tail = root;
       }

     inOrder(root->right);
        
    }
    

    Node* treeToDoublyList(Node* root) {
        if(!root) return root;
        inOrder(root);
        tail->right = head;
        head->left = tail;
        return head;
    }
};