class MedianFinder {
   public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int> > right;
    priority_queue<int> left;
    MedianFinder() {}

    void addNum(int num) {
        // left > right by most 1. should be equal.
        if (left.size() == 0 && right.size() == 0) {
            left.push(num);
        } else if (num >= left.top()) {
            right.push(num);
        } else if (right.size() > 0 && num <= right.top()) {
            left.push(num);
        } else {
            left.push(num);
        }
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        } else if (left.size() - 1 > right.size()) {
            right.push(left.top());
            left.pop();
        }
    }

    double findMedian() {
        if ((left.size() + right.size()) & 1) {
            return left.top() / 1.0;
        } else {
            return (left.top() + right.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */