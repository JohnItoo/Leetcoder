class Solution {
   public:
    int longestSubstring(string s, int k) {
        int n = s.length();
        int best = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<char> done;
            unordered_map<char, int> undone;
            int curr = 0;
            for (int j = i; j < n; j++) {
                if (done.find(s[j]) != done.end()) {
                    // increase length if all to //left is done
                    if (undone.size() == 0) {
                        curr = (j - i) + 1;
                    }
                    continue;
                }
                undone[s[j]]++;
                if (undone[s[j]] >= k) {
                    undone.erase(s[j]);
                    done.insert(s[j]);
                    if (undone.size() == 0) {
                        curr = (j - i) + 1;
                    }
                }
            }
            best = max(curr, best);
        }

        return best;
    }
};