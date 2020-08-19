class Lock {
private:
    int org;
    int end;

public: Lock() {};

public :
    void set_org(int start) {
        org = start;
    }

    void set_end(int finish) {
        end = finish;
    }

    int get_org() {
        return org;
    }

    int get_end() {
        return end;
    }
};

class Solution {

private:
    static bool comp(Lock a, Lock b) {
        if (a.get_end() == b.get_end())
            return a.get_org() < b.get_org();
        return a.get_end() < b.get_end();
    }

public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<Lock> locks(n);
        for (int i = 0; i < n; i++) {
            Lock l = Lock();
            l.set_org(pairs[i][0]);
            l.set_end(pairs[i][1]);
            locks[i] = l;
        }

        sort(locks.begin(), locks.end(), comp);

        int mx = 0;
        vector<bool> has(n, false);
        for (int  i = 0; i < n; i++) {
            if (has[i]) continue;
            Lock prev = locks[i];
            has[i] = true;
            int len = 1;
            for (int j = i; j < n; j++) {
                if (has[j]) continue;
                Lock curr = locks[j];
                if (curr.get_org() > prev.get_end()) {
                    prev = curr;
                    has[i] = true;
                    len++;
                }
            }
            mx = max(len, mx);
        }
        return mx;
    }
};