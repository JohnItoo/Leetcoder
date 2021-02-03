#include <bits/stdc++.h>
using namespace std;

int solve(vector<string> vs) {
	int n = vs.size();
	int lls = 0;
	int ls = 0;
	int total = 0;
	for (int i = 0; i < n; i++) {
		string curr = vs[i];
		if (curr == "Z") {
			total -= ls;
			swap(lls, ls);
			lls = 0;
		} else {
			int sc = 0;
			if (curr == "+") {
				sc = lls + ls;
			} else if (curr == "X") {
				sc = 2 * ls;
			} else {
				sc = stoi(curr);
			}
			total += sc;
			lls = ls;
			ls = sc;
		}
	}
	return total;
}

int main() {
	int n; cin >> n;
	vector<string> vs(n);
	for (int i = 0; i < n; i++) cin >> vs[i];

	cout << solve(vs) << endl;
	return 0;
}