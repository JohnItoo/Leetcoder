class Solution {
    struct myComp {
        bool operator()(pair<int, string> const &a,
                        pair<int, string> const &b) const noexcept {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

   public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        int n = words.size();
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            mp[words[i]]++;
        }

        priority_queue<pair<int, string>, vector<pair<int, string>>, myComp> pq;
        for (auto it : mp) {
            pq.push(make_pair(it.second, it.first));
        }

        vector<string> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};