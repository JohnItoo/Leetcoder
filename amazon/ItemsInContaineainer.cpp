#include <bits/stdc++.h>

using namespace std;

vector<int> result(string s, vector<int> starts, vector<int> ends) {

	vector<int> ans;
	int n = s.length();
	vector<int> pref(n + 1, 0);

	int last = 0;
	int start = 0;
	while (s[start] == '*') start++;
	for (int i = start; i < n; i++) {
		if (s[i] == '|') {
			pref[i + 1] = pref[i] + last;
			last = 0;
		} else {
			pref[i + 1] = pref[i];
			last++;
		}
	}
	map<pair<int, int>, int> mp;
	for (int i = 0; i < starts.size(); i++) {
		for (int j = 0; j < ends.size(); j++) {
			pair<int, int> p = make_pair(starts[i], ends[j]);
			if (mp.find(p) == mp.end()) {
				mp[p] = 1;
				ans.push_back(pref[p.second] - pref[p.first]);
			}

		}
	}
	return ans;
}

int main() {
	string s; cin >> s;
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int m; cin >> m; vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];

	vector<int> res = result(s, a, b);
	for (int i = 0 ; i < res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;

}