class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int> > pq;
        for (auto it : mp) {
            pq.push(make_pair(it.second, it.first));
        }

        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;

    }
};