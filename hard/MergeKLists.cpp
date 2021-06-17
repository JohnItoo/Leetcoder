/**
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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    map<int, int> mp;
    if (lists.size() == 0) return NULL;

    bool betLst = false;
    for (int i = 0; i < lists.size(); i++) {
      ListNode* curr = lists[i];
      while (curr != NULL) {
        mp[curr->val]++;
        betLst = true;
        curr = curr->next;
      }
    }
    if (!betLst) return NULL;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : mp) {
      pq.push(it.first);
    }

    ListNode* head = NULL;
    ListNode* tail = NULL;

    while (pq.size() > 0) {
      int nw = pq.top();
      int freq = mp.find(nw)->second;
      pq.pop();

      for (int i = 0; i < freq; i++) {
        ListNode* lst = new ListNode(nw);

        if (head == NULL) {
          head = lst;
          tail = lst;
        } else {
          tail->next = lst;
          tail = lst;
        }
      }

    }
    tail->next = NULL;
    return head;

  }
};