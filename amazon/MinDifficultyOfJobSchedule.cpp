//THIS PROBLEM IS ALSO KNOWN AS Beta-Testing.

#include <bits/stdc++.h>
using namespace std;
int D = 0;
vector<int> difc;

int solve(int i , int j) {
	if (j == 0) return 0;
	int hw = difc.size() - (j - 1);
	int result = 1e9+7;
	for (int t = 1; t <= hw; t++) { //max jobs we can have in this day j
		int mx = 0;
		for (int lft = i; lft < i + t; lft++) { 
			mx = max(mx, difc[lft]);
		}
		// cout << mx << " " << j << endl;
		result = min(result, mx + solve(i + t, j - 1));
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