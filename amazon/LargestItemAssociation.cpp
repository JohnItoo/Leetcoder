#include <bits/stdc++.h>
using namespace std;
int main() {
	int n; cin >> n;
	vector<pair<string, string> > vps;
	for(int i = 0; i < n; i++) {
		string x, y;
		cin >> x >> y;
		vps.push_back(make_pair(x,y));
	}

	vector<string> ans = result(vps);
	for(string r: ans) cout << r << endl;

	return 0;
}