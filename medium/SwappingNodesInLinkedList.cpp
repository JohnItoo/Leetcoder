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
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        int left = 0;
        int right = 0;
        while (temp != NULL) {
            n++;
            if (n == k) {
                left = temp->val;
            }
            temp = temp->next;
        }
        temp = head;
        int end = n - k + 1;
        int ct = 0;
        while (temp != NULL) {
            ct++;
            if (ct == end) {
                right = temp->val;
                temp->val = left;
            }
            temp = temp->next;
        }
        temp = head;
        ct = 0;
        while (temp != NULL) {
            ct++;
            if (ct == k) {
                temp->val = right;
            }
            temp = temp->next;
        }
        return head;
    }
};