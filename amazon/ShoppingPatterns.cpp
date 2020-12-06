#include <bits/stdc++.h>
using namespace std;
//IMPROVE? Currently O(N * (V+E));

int solve(vector<vector<int> > graph) {
	int vertices = graph.size();
	int ans = 1e9;
	for (int i = 1; i < vertices; i++) {
		stack<pair<int, pair<int, int> > > dfs;
		dfs.push(make_pair(i, make_pair(i, 0)));
		map<int, int> visited;
		while (!dfs.empty()) {
			pair<int, pair<int, int> > tp = dfs.top(); dfs.pop();
			int previous = tp.first;
			int current = tp.second.first;
			int depth = tp.second.second;
			if (visited.find(current) != visited.end()) continue;
			visited[current] = 1;
			for (int edge : graph[current]) {
				if (edge == i &&  depth == 2) {
					//found trio;
					cout << i << " " << previous << " " << current << endl;
					int sm = (graph[i].size() - 2) + (graph[previous].size() - 2) + (graph[current].size() - 2);
					ans = min(sm, ans);
				} else {
					pair<int, pair<int, int> > nw = make_pair(current, make_pair(edge, depth + 1));
					dfs.push(nw);
				}
			}
		}
	}
	return ans;
}

int main() {
	int vertices; cin >> vertices;
	vector<vector<int> > graph(vertices + 1, vector<int>());
	int n; cin >> n;
	vector<int> a(n); vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	for (int i = 0; i < n; i++) {
		graph[a[i]].push_back(b[i]);
		graph[b[i]].push_back(a[i]);
	}
	int ans = solve(graph);
	cout << ans << endl;

	return 0;
}