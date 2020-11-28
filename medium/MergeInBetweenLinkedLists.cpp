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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l1head = list1;
        ListNode* l1tail = list1;
        ListNode* curr = list1;

        int ct = 0;
        while (ct + 1 < a) {
            l1tail = l1tail->next;
            curr = curr->next;
            ct++;
            cout << ct << endl;
        }


        while (ct <= b) {
            curr = curr->next;
            ct++;
            cout << ct << endl;
        }

        while (list2 != NULL) {
            l1tail->next = list2;
            l1tail = list2;
            list2 = list2->next;
        }
        // l1tail->next = list2;
        l1tail->next = curr;
        return l1head;
    }
};