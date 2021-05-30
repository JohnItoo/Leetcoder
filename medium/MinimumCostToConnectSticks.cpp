class Solution {
   public:
    int connectSticks(vector<int>& sticks) {
        int n = sticks.size();
        if (n == 1) return 0;
        priority_queue<int, vector<int>, greater<int> > pq;
        for (int stick : sticks) {
            pq.push(stick);
        }
        int total = 0;
        while (pq.size() > 1) {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int r = f + s;
            pq.push(r);
            total += r;
        }
        return total;
    }
};