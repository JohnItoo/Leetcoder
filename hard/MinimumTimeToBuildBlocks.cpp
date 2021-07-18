class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<> > pq;
        for(auto& block : blocks) {
            pq.push(block);
        }
        while(pq.size() > 1) {
            int topMost = pq.top();
            pq.pop();
            
            int secondToTop = pq.top();
            pq.pop();
            
            pq.push(secondToTop + split);
        }
        
        return pq.top();
    }
};