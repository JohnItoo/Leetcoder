#include <bits/stdc++.h>

using namespace std;

int connect(vector<int> ropes) {
	int n = ropes.size();
	priority_queue<int, vector<int>, greater<int> > pq;
	for (int i = 0; i < n; i++) pq.push(ropes[i]);
	int cost = 0;
	while (pq.size() > 1) {
		int first = pq.top(); pq.pop();
		int second = pq.top(); pq.pop();
		cost += (first + second);
		pq.push(first + second);
	}

	return cost;

}

int main() {
	int n; cin >> n;
	vector<int> ropes(n);
	for (int i = 0; i < n; i++) cin >>  ropes[i];
	cout << connect(ropes) << endl;
}