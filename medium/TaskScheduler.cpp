class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int sz = tasks.size();
        unordered_map<char, int> freqMap;
        
        if(n == 0) return sz;
        
        for(int i = 0; i < sz; i++) {
            char c = tasks[i];
            freqMap[c]++;
        }
        priority_queue< pair<int, int> > maxHeap;
        
        
        for(auto ii : freqMap) {
            maxHeap.push({ii.second, ii.first});
        }
        //get MaxFrequency
        
        pair<int, int> mxOccurrence = maxHeap.top();
        maxHeap.pop();
        
        int otherCount = 0; // number of other characters with the same maxFrequency;
        int mxFrequency = mxOccurrence.first;
        
        while(!maxHeap.empty() && maxHeap.top().first == mxFrequency) {
            maxHeap.pop();
            otherCount++;
        }
        // 1 + (sz-1) *( n+1) derived from a + (n-1)d;
        int result = 1 + ( (mxFrequency - 1) * (n+1) ) + otherCount;
        return max(result, sz);
        
        
        
    }
};