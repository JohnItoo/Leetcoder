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
    // O(NLogN) - time complexity: O(N) - space complexity
    ListNode* sortList(ListNode* head) {
        ListNode* curr = head;
        vector<int> aux;
        while (curr) {
            aux.push_back(curr->val);
            curr = curr->next;
        }
        sort(aux.begin(), aux.end());
        curr = head;
        int i = 0;
        while (curr) {
            curr->val = aux[i++];
            curr = curr->next;
        }
        return head;
    }
};