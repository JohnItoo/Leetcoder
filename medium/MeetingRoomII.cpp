class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        multiset<pair<int, int> > times;
        int n = intervals.size();
        for(int i = 0; i < n; i++) {
            times.insert({intervals[i][0], intervals[i][1]});
        }
        int ans = 0;
        while(!times.empty()) {
            auto nextTimeIt = times.begin();
            ans++;
            while(nextTimeIt != times.end()) {
                pair<int, int> nextTime = *nextTimeIt;
                times.erase(nextTimeIt);
                nextTimeIt = times.lower_bound({nextTime.second, nextTime.second});
            }
        }
        return ans;
    }
};