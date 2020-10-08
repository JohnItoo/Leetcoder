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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = NULL;
    ListNode* tail = NULL;
    int carry = 0;
    while (l1 != NULL && l2 != NULL) {
      int x = l1->val;
      int y = l2->val;
      int sum = x + y + carry;

      if (sum >= 10) {
        carry = 1;
        sum -= 10;
      } else {
        carry = 0;
      }

      if (head == NULL) {
        head = new ListNode(sum);
        tail = head;
      } else {
        ListNode* nw = new ListNode(sum);
        tail->next = nw;
        tail = nw;
      }
      l1 = l1->next;
      l2 = l2->next;
    }

    ListNode *rem = l1 != NULL ? l1 : l2;

    while (rem != NULL) {
      int use = carry + rem->val;
      if (use >= 10) {
        use -= 10;
        carry = 1;
      } else {
        carry = 0;
      }

      if (head == NULL) {
        head = new ListNode(use);
        tail = head;
      } else {
        ListNode* nw = new ListNode(use);
        tail->next = nw;
        tail = nw;
      }
      rem = rem->next;
    }

    if (carry > 0) {
      ListNode* nw = new ListNode(carry);
      tail->next = nw;
      tail = nw;
    }

    return head;
  }
};