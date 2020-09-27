class ThroneInheritance {
    string king;
    map<string, vector<string>> mp;
    map<string, int> dt;
    vector<string> result;

    void dfs(string parent, vector<string> &result) {
        auto dh = dt.find(parent);
        if (dh == dt.end()) result.push_back(parent);
        auto it = mp.find(parent);
        if (it == mp.end()) return;
        vector<string> qt = it->second;

        for (string currchild : qt) {
            dfs(currchild, result);
        }
    }

public:
    ThroneInheritance(string kingName) {
        king = kingName;

    }

    void birth(string parentName, string childName) {
        if (mp.find(parentName) != mp.end()) {
            ((mp.find(parentName))->second).push_back(childName);
        } else {
            vector<string> vs;
            vs.push_back(childName);
            mp[parentName] = vs;
        }
    }

    void death(string name) {
        dt[name] = 1;
    }

    vector<string> getInheritanceOrder() {

        vector<string> result;

        dfs(king, result);

        return result;
    }


};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */