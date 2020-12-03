#include <bits/stdc++.h>
using namespace std;

vector<string> result (vector<pair<string, string> > vps) {
	int n = vps.size();
	set<string> st;
	map<string, vector<string> > gp;
	for (int i = 0; i < n; i++) {
		st.insert(vps[i].first);
		st.insert(vps[i].second);
		gp[vps[i].first].push_back(vps[i].second);
		gp[vps[i].second].push_back(vps[i].first);
	}
	map<string, int> mp;
	vector<string> diffs[st.size()];
	int highest = 0;
	int idx = 0;
	for (auto it = st.begin(); it != st.end(); ++it) {
		string st = *it;
		if (mp.find(st) != mp.end()) continue;
		stack<string> stk;
		stk.push(st);
		int curr = 0;
		vector<string> dz;
		while (!stk.empty()) {
			string tp = stk.top(); stk.pop();
			if (mp.find(tp) != mp.end()) continue;
			mp[tp] = 1;
			dz.push_back(tp);
			curr++;
			vector<string> kids = gp[tp];
			for (auto kid : kids) {
				stk.push(kid);
			}
		}
		sort(dz.begin(), dz.end());
		if (dz.size() > highest) highest = dz.size();
		diffs[idx] = dz;
		idx++;
	}
	int index = -1;

	for (int i = 0; i < st.size(); i++) {
		if (diffs[i].size() != highest) continue;
		if (index == -1) index = i;
		else {
			if (diffs[index][0] > diffs[i][0]) {
				index = i;
			}
		}
	}
	return diffs[index];
}
int main() {
	int n; cin >> n;
	vector<pair<string, string> > vps;
	for (int i = 0; i < n; i++) {
		string x, y;
		cin >> x >> y;
		vps.push_back(make_pair(x, y));
	}

	vector<string> ans = result(vps);
	for (string r : ans) cout << r << endl;

	return 0;
}