#include <bits/stdc++.h>
using namespace std;

int minRev(vector<vector<double> > pr, int rt) {
	int n = pr.size();
	double sm = 0;
	for (int i = 0; i < n; i++) {
		double perc = (double) pr[i][0] / pr[i][1];
		perc *= 100;
		sm += perc;
	}
	double need = rt * n;
	cout << need << endl;
	int ans = 0;

	while (sm < need) {
		int idx = 0;
		while (idx < pr.size() && pr[idx][0] == pr[idx][1]) idx++; // skip all 100percenters from the left;
		int mxIndex = idx;
		double mxValue =  ((pr[mxIndex][0] + 1) / (pr[mxIndex][1] + 1)) - (pr[mxIndex][0] / pr[mxIndex][1]); // default Max Impact is the first Non 100 percenter in array.
		for (int i = 0; i < n; i++) {

			if (pr[i][0] == pr[i][1]) continue; // skipping 100 percenters
			double curr =  (((pr[i][0] + 1) / (pr[i][1] + 1)) - pr[i][0] / pr[i][1]) ; //
			if (curr > mxValue) {
				mxValue = curr;
				mxIndex = i;
			}
		}
		double x = pr[mxIndex][0];
		double y = pr[mxIndex][1];

		sm -= (double) (x / y) * 100;
		sm += (double) ((x + 1) / (y + 1)) * 100;
		pr[mxIndex][0] = x + 1;
		pr[mxIndex][1] = y + 1;
		ans++;
	}

	return ans;

}

int main() {
	int n; cin >> n;
	vector<vector<double> > pr(n, vector<double>(2));
	for (int i = 0; i < n; i++) {
		double x, y; cin >> x >> y;
		pr[i][0] = x;
		pr[i][1] = y;
	}
	int rt; cin >> rt;

	cout << minRev(pr, rt) << endl;

}