#include <bits/stdc++.h>
using namespace std;

struct myComp {
	bool operator()(pair<int, double> const& pd, pair<int, double> const& pq) {
		if (pd.first == pq.first) return pd.second > pq.second;
		return pd.first > pq.first;
	}


};

int minRev(vector<vector<int> > pr, int rt) {
	int n = pr.size();
	priority_queue<pair<int, double>, vector<pair<int, double> >, myComp > pq;
	double sm = 0;
	for (int i = 0; i < n; i++) {
		if (pr[i][0] == pr[i][1]) continue;
		double perc = (double) pr[i][0] / pr[i][1];
		perc *= 100;
		pair<int, double> pdd = make_pair(pr[i][1], perc);
		sm += perc;
		pq.push(pdd);
	}
	sm += 100* (n - pq.size());
	int need = rt * n;
	int ans = 0;
	cout << need << endl;

	while(sm < need && !pq.empty()) {
		pair<int, double> curr = pq.top(); pq.pop();
		sm -= curr.second;
		// cout << curr.first << " " << curr.second << " here\n";
		int num = (curr.second * curr.first) / 100;
		double nw = (double) (num + 1)/ (curr.first + 1);
		nw *= 100;
		sm += nw;
		pair<int, double> pqd = make_pair(num+1, nw);
		pq.push(pqd);
		ans++;
	}

	return ans;

}

int main() {
	int n; cin >> n;
	vector<vector<int> > pr(n, vector<int>(2));
	for (int i = 0; i < n; i++) {
		int x, y; cin >> x >> y;
		pr[i][0] = x;
		pr[i][1] = y;
	}
	int rt; cin >> rt;

	cout << minRev(pr, rt) << endl;

}