//THIS PROBLEM IS ALSO KNOWN AS Beta-Testing.

#include <bits/stdc++.h>
using namespace std;
int D = 0;
vector<int> difc;

int solve(int i , int j) {
	if (j == 1) {
		int lft = i;
		int mx = 0;
		while (lft < difc.size()) mx = max(mx, difc[lft++]);
		return mx;
	}
	int hw = difc.size() - (j - 1); // we can take all jobs from i to hw-1 on  this day j
	int result = 1e9 + 7;
	for (int t = i; t < hw; t++) {
		int mx = 0;
		for (int lft = i; lft <=  t; lft++) {
			mx = max(mx, difc[lft]);
		}
		// cout << mx << " " << j << endl;
		int curr = mx + solve(t, j - 1);
		if (curr < result) {
			cout << t << " t : curr " << j << " " << curr << endl;
			result = curr;
		}
	}

	return result;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		difc.push_back(x);
	}
	cin >> D;
	int ans = solve(0, D);
	cout << ans << endl;
}