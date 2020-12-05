#include <bits/stdc++.h>
using namespace std;
bool comp(string &s1, string &s2) {
	return stoi(s1) > stoi(s2);
}

vector<string> solve(vector<vector<string> >  vvs,  int tr) {
	vector<string> ans;
	map<string, int> mp;
	for (int j = 0; j < vvs.size(); j++) {
		vector<string> vcurr = vvs[j];
		string curr = vcurr[0];
		int i = 0;
		int last = 0;
		int ct = 0;
		string prev = "";
		string next = "";
		while (i < curr.length() && ct < 2) {
			if (curr[i] == ' ') {
				string sub = curr.substr(last, i - last);
				if (prev == "") prev = sub;
				else {
					next = sub;

				}
				i++;
				last = i;
				ct++;
			} else {
				i++;
			}
		}
		if (prev == next) {
			mp[prev]++;
		} else {
			mp[prev]++;
			mp[next]++;
		}
	}

	for (auto xx : mp) {
		if (xx.second >= tr) {
			ans.push_back(xx.first);
		}
	}
	sort(ans.begin(), ans.end(), comp);


	return ans;
}


int main() {
	int n; cin >> n;
	vector<vector<string> > vvs(n);
	cin >> ws;

	for (int i = 0; i < n; i++) {
		vector<string> vs;
		string s; getline(cin, s);
		vs.push_back(s);
		vvs[i] = vs;
	}
	int tr; cin >> tr;
	vector<string> result = solve(vvs, tr);
	for (string ans : result) cout << ans << endl;
	return 0;
}