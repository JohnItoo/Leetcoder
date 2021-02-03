/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while(head != NULL) {
              Node* curr = new Node(head->val);
             mp[head] = curr;
             
          head = head->next;
        }
        for(auto ii : mp) {
            if((ii.first)->random != NULL) {
                Node* left = ii.first;
                Node* second = ii.second;
                second->random = mp[left->random];
            }
        }
         head = temp;
        Node* deep = mp[temp];
        while(head != NULL) {
            Node* next = head->next;
            deep->next = mp[next];
            head = head->next;
            deep = deep->next;
        }
       return mp[temp];
    }
};