#include <bits/stdc++.h>
using namespace std;

int minRev(vector<vector<int> > pr) {
	int n = pr.size();
	priority_queue<pair<int, double> > pq;
	double sm = 0;
	for (int i = 0; i < n; i++) {
		if (pr[i][0] == pr[i][1]) continue;
		double perc = pr[i][0] / pr[i][1];
		perc *= 100;
		pair<int, double> pdd = make_pair(pr[i][1], perc);
		sm += perc;
		pq.push(pdd);
	}
}

int main() {
	int n; cin >> n;
	vector<vector<int> > pr(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		pr[i][0] = x;
		pr[i][1] = y;
	}

	cout << minRev(pr) << endl;

}