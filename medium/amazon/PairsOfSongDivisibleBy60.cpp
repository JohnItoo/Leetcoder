class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        map<int, int> timeMap;
        for (int i = 0; i < n; i++) {
            timeMap[time[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int currTime = time[i];
            for (int t = 1; t <= 20; t++) {
                int targetTime = 60 * t;
                if (currTime >= targetTime) continue;
                int diff = targetTime - currTime;
                int frequency = timeMap.find(diff) == timeMap.end() ? 0 : timeMap[diff];
                if (currTime == diff) frequency--;
                ans += frequency;
            }
        }

        return ans / 2;
    }
};