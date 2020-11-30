#include <bits/stdc++.h>

using namespace std;


//Catch: The reason why we cannot just sort ropes and add incrementally from left to right is that there might be a better pair in the array so it will be crazy to use the array as is.
// We then have to use a min heap which ensures we will always get the first
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