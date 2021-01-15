class FirstUnique {
   public:
    list<int> q;
    map<int, int> mp;
    map<int, int> barred;
    FirstUnique(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            add(nums[i]);
        }
    }

    int showFirstUnique() {
        if (!q.empty()) {
            return *(q.begin());
        }
        return -1;
    }

    void add(int value) {
        if (mp.count(value)) {
            auto it = find(q.begin(), q.end(), value);
            q.erase(it);
            mp.erase(value);
            barred[value]++;
        } else if (barred.count(value) == 0) {
            q.push_back(value);
            mp[value]++;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */