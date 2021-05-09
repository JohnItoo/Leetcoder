class Solution {
   public:
    using ll = long long;
    priority_queue<ll> pq;
    bool isPossible(vector<int>& target) {
        ll sm = 0;
        int n = target.size();
        for (int i = 0; i < n; i++) {
            int curr = target[i];
            pq.push(curr * 1LL);
            sm += (curr * 1LL);
        }
        while (pq.top() != 1) {
            ll top = pq.top();
            pq.pop();
            sm -= top;
            if (top <= sm || sm < 1) return false;
            top %= sm;
            sm += top;

            pq.push(top);
        }
        return true;
    }
};