class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        set<int> keys;
        int n = nums.size();
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());
        
        freq[nums[0]]++;
        
        for(int i = 1; i < n; i++) {
            freq[nums[i]]++;
            
            int diff = nums[i] - nums[0];
            if(diff <= 0 || diff & 1) continue;
            keys.insert(diff/2);
        }
        vector<int> result;
        for(int key : keys) {
            unordered_map<int, int> freqcopy = freq;
            vector<int> res;
            bool poss = true;
            
            for(int i = 0; i < n; i++) {
                if(freqcopy.find(nums[i]) == freqcopy.end()) continue;
                int cur = freqcopy[nums[i]];
                if(cur == 1) {
                    freqcopy.erase(nums[i]);
                } else {
                    freqcopy[nums[i]]--;
                }
                int target = nums[i] + key;
                int val = target + key;
                if(freqcopy.find(val) == freqcopy.end()) {
                    poss = false; 
                    break;
                } else {
                    res.push_back(target);
                    int othercurr = freqcopy[val];
                    
                    if(othercurr == 1) {
                        freqcopy.erase(val);
                    } else {
                        freqcopy[val]--;
                    }
                }
            }
            
            if(poss && res.size() == n/2) {
                return res;
            }
                    
        }
        return result;
        
        
    }
};