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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL ) return head;
        ListNode* rightHead = NULL;
        ListNode* leftHead = NULL;
        ListNode* rightTail = NULL;
        ListNode* leftTail = NULL;

        while (head != NULL) {
            if (head->val < x) {
                if (leftHead == NULL) {
                    leftHead = head;
                    leftTail = head;
                } else {
                    leftTail->next = head;
                    leftTail = head;
                }
            } else {
                if (rightHead == NULL) {
                    rightHead = head;
                    rightTail = head;
                } else {
                    rightTail->next = head;
                    rightTail = head;
                }
            }
            head = head->next;
        }
        if (leftTail != NULL) leftTail->next = rightHead;
        if (rightTail != NULL) rightTail->next = NULL;

        return leftHead != NULL ? leftHead : rightHead;
    }
};