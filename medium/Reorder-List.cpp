/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* right = head;
        stack<ListNode*> stc;
        int ct = 0;
        while(right) {
            stc.push(right);
            right = right->next;
            ct++;
        }

        ListNode* curr = head;
        ListNode* next = nullptr;
        bool dn = true;
        int val = 0;
        while(val < ct) {
         val++; 
         if(val < ct) {
            next = curr->next;
             curr->next = stc.top();
             stc.pop();
             val++;
             curr = curr->next;
         }
            
        if(val < ct) {
            curr->next = next;
            curr = curr->next;
        } 
            
       }
       curr->next = nullptr;
        return;
    }
};