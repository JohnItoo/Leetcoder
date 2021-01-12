class LRUCache {
   public:
    int cap = 0;
    int time = 0;
    map<int, pair<int, int> > cache;  // key : <time, value>
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        time++;
        if (cache.count(key)) {
            pair<int, int> tv = cache[key];
            cache[key] = make_pair(time, tv.second);
            return tv.second;
        }
        return -1;
    }

    void put(int key, int value) {
        time++;
        update(key, value);
        if (cache.size() > cap) {
            removeLRU(key);
        }
    }

    void update(int key, int value) { cache[key] = make_pair(time, value); }

    void removeLRU(int lastkey) {
        int least = time;
        int key = lastkey;
        for (auto curr : cache) {
            pair<int, int> tv = curr.second;
            if (tv.first < least) {
                least = tv.first;
                key = curr.first;
            }
        }
        cache.erase(key);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */