/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> nodes;
        
        bool ans = false;
        
        while(head != NULL) {
            if(nodes.find(head) != nodes.end()) {
                ans = true;
                break;
            }
            nodes[head] = 1;
            head = head->next;
        }
        
        return ans;
    }
};