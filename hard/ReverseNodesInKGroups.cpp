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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* tail = head;
        
        ListNode* nH = NULL;
        ListNode* nT = NULL;
        
        while(tail != NULL) {
            int curr = 0;
            stack<int> st;
            

            while(tail != NULL && curr <  k) {
                int dz = tail->val;
                st.push(dz);
                curr++;
                tail = tail->next;
            }
            
            if(curr == k) {
                
                while(!st.empty()) {
                     int x = st.top(); st.pop();
                     if(nH == NULL) {
                   
                    nH = new ListNode(x);
                    nT = nH;
                  } else {
                    ListNode* nex = new ListNode(x);
                    nT->next = nex;
                  nT = nex;            
                  }
               }
            } else {
                while(head != NULL) {
                    ListNode* nww = new ListNode(head->val);
                    nT->next = nww;
                    nT = nww;
                    head = head->next;
                }
                tail = head;
            }
            head = tail;
        }
        
        return nH;
        
    }
};