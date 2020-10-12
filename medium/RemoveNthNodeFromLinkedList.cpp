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
private: ListNode* reverseLinkedList(ListNode* head) {
        ListNode* curr = head;
        ListNode* next = NULL;
        ListNode* prev = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head->next == NULL) return NULL;
        ListNode* listHead = NULL;
        ListNode* listTail = NULL;

        int i = 1;
        ListNode* currhead = reverseLinkedList(head);
        ListNode* fakehead = currhead;
        while (i < n) {
            i++;
            cout << fakehead->val << "\n";
            fakehead = fakehead->next;
        }
        ListNode* toRemove = fakehead;
        cout << toRemove->val << "\n";


        head = reverseLinkedList(currhead);



        while (head != NULL) {
            if (head != toRemove) {
                if (listHead == NULL) {
                    listHead = head;
                    listTail = head;
                } else {
                    listTail->next = head;
                    listTail = head;
                }
            }
            head = head->next;
        }
        listTail->next = NULL;
        return listHead;

    }
};