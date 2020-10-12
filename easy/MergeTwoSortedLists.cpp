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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* tail = NULL;
        
        while(l1 != NULL || l2 != NULL) {
            ListNode* smallestNode = NULL;
            if(l1 != NULL && l2 != NULL) {
                if(l1->val < l2->val) {
                    smallestNode = l1;
                    l1 = l1->next;
                } else {
                    smallestNode = l2;
                    l2 = l2->next;
                }
            } else {
                if(l1 != NULL) {
                    smallestNode = l1;
                    l1 = l1->next;
                } else {
                    smallestNode = l2;
                    l2 = l2->next;
                }
            }
            
            if (head == NULL) {
                head = smallestNode;
            } else {
                tail->next = smallestNode;
            }
           tail = smallestNode;
           tail->next = NULL;
        }
        return head;
    }
};