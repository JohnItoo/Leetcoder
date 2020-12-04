#include <bits/stdc++.h>

using namespace std;

vector<int> getTimes(vector<int> times, vector<int> dir) {
	int n = times.size();
	//m is equal to n since the every individual i that approaches the turnstile, has a commensurate direction.
	queue<pair<int, int> > leaves;
	queue<pair<int, int> >  enters;
	pair<int, int> lastUsed = make_pair(-2, -1); // <time last used, direction>.
	for (int i = 0; i < n; i++) {
		if (dir[i]) leaves.push(make_pair(times[i], i));
		else enters.push(make_pair(times[i], i));
	}
	vector<int> result(n);

	while (!leaves.empty() && !enters.empty()) {
		int cl = (leaves.front()).first;
		int el = (enters.front()).first;
		if (cl < el && cl > lastUsed.first) {
			lastUsed = make_pair(cl, 1);
			result[(leaves.front()).second] = cl;
			leaves.pop();

			continue;
		} else if (el < cl && el > lastUsed.first) {
			lastUsed = make_pair(el, 0);
			result[(enters.front()).second] = el;
			enters.pop();

			continue;
		}

		if ((lastUsed.first + 1  == el || lastUsed.first == el)  &&  lastUsed.second == 0) {
			// To allow an entering person to pass the turnstile, the turnstile must have been used in the previous second to
			// enter. Previous second means that the current second - 1 or the current second (which forces us to wait till the next second)
			if (el <= lastUsed.first) el = lastUsed.first + 1;
			result[(enters.front()).second] = el;
			lastUsed = make_pair(el, 0);
			enters.pop();
		} else {
			if (cl <= lastUsed.first) cl = lastUsed.first + 1;
			result[(leaves.front()).second] = cl;
			lastUsed = make_pair(cl, 1);
			leaves.pop();
		}
	}

	int lsu = lastUsed.first < 0 ? 0 : lastUsed.first + 1;

	while (!leaves.empty()) {
		lsu = max(lsu, (leaves.front()).first);
		result[(leaves.front()).second] = lsu++;
		leaves.pop();
	}

	while (!enters.empty()) {
		lsu = max(lsu, (enters.front()).first);
		result[(enters.front()).second] = lsu++;
		enters.pop();
	}

	return result;
}

int main() {
	int n; cin >> n;
	vector<int> times(n);
	for (int i = 0; i < n; i++) {
		cin >> times[i];
	}
	int m; cin >> m;
	vector<int> dir(m);
	for (int i = 0; i < m; i++) cin >> dir[i];

	vector<int> result = getTimes(times, dir);

	for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
	return 0;
}