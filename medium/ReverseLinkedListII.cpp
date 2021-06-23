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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        ListNode* leftPrev = NULL;
        bool end = false;
        int i = 1;
        while(i < left) {
            prev = curr;
            curr = curr->next;
            i++;
        }
        leftPrev = prev;
        ListNode* leftNode = curr;
        while(i <= right) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            i++;
        }
        if(leftPrev) {
            leftPrev->next = prev;
        }
        leftNode->next = curr;
        if(left == 1) return prev;
        return head;
        
    }
};