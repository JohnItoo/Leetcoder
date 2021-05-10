class Solution {
   public:
    // Priority Queue <Max Heap> O(N)
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int> > pq;
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < k; i++) {
            pq.push(make_pair(nums[i], i));
        }
        res.push_back(pq.top().first);
        for (int i = k; i < n; i++) {
            pq.push(make_pair(nums[i], i));
            while (pq.top().second <= i - k) {
                pq.pop();
            }
            res.push_back(pq.top().first);
        }
        return res;
    }
};

// DEQUE O(N)
class Solution {
   public:
    deque<int> deck;
    int n = 0;
    int k = 0;
    vector<int> a;

    void cleanDeck(int i) {
        if (!deck.empty() && deck.front() == i - k) {
            deck.pop_front();
        }
        while (!deck.empty() && a[deck.back()] < a[i]) {
            deck.pop_back();
        }
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int y) {
        n = nums.size();
        a = nums;
        k = y;
        for (int i = 0; i < k; i++) {
            cleanDeck(i);
            deck.push_back(i);
        }

        vector<int> result;
        result.push_back(nums[deck.front()]);

        for (int i = k; i < n; i++) {
            cleanDeck(i);
            deck.push_back(i);
            cout << deck.front() << endl;
            result.push_back(nums[deck.front()]);
        }

        return result;
    }
};