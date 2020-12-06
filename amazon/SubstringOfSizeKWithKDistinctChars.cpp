#include <bits/stdc++.h>
using namespace std;

vector<string> solve(string s, int k) {
	int n = s.length();
	int i = 0;
	int j = 0;
	map<char, int> mpc;
	int ct = 0;
	set<string> ans;

	while (i < n && j < n) {
		if(j - i == k-1 && mpc.find(s[j]) == mpc.end()) {
			string sub = s.substr(i, k);
			mpc.erase(s[i]);
			ans.insert(sub);
			i++;
			j++;
			continue;
		}
		if (mpc.find(s[j]) == mpc.end()) {
			mpc[s[j]] = 1;
			j++;
		} else {
			i++;
		}

	}
	vector<string> res;
	for(string an : ans) res.push_back(an);
	return res;
}

int main() {
	string s; cin >> s;
	int k; cin >> k;
	vector<string> subs = solve(s, k);
	for (string ss : subs) cout << ss << endl;
}