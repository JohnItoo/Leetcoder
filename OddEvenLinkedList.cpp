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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return head;
        int idx = 1;
        ListNode* oddHead = NULL;
        ListNode* oddTail = NULL;
        ListNode* evenHead = NULL;
        ListNode* evenTail = NULL;
        while (head != NULL) {
            if (idx & 1) {
                if (oddHead == NULL) {
                    oddHead = head;
                    oddTail = head;
                } else {
                    oddTail->next = head;
                    oddTail = head;
                }
            } else {
                if (evenHead == NULL) {
                    evenHead = head;
                    evenTail = head;
                } else {
                    evenTail->next = head;
                    evenTail = head;
                }
            }
            idx += 1;
            head = head->next;
        }
        if (oddTail != NULL) oddTail->next = evenHead;
        if (evenTail != NULL) evenTail->next = NULL;
        return oddHead;
    }
};