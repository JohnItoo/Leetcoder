class Solution {
    struct myComp {
        bool operator() (pair<int, int> const&a, pair<int, int> const&b) const noexcept {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };
public:
    int calculateSQEuclideanDistance(vector<int>& pointOne) {
        return (pointOne[0] * pointOne[0]) + (pointOne[1] * pointOne[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> > , myComp> pq;
        for (int i = 0; i < points.size(); i++) {
            vector<int> currPoint = points[i];
            int dist = calculateSQEuclideanDistance(currPoint);
            pq.push(make_pair(dist, i));
        }
        vector<vector<int> > result;
        for (int i = 0; i < k; i++) {
            pair<int, int> tp = pq.top(); pq.pop();
            result.push_back(points[tp.second]);
        }
        return result;
    }
};