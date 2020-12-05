#include <bits/stdc++.h>
using namespace std;
int INF = 2e8;

int result(vector<int> a, int instances) {
	int i = 1;
	int n = a.size();
	while (i <= n) {
		int curr = a[i - 1];
		if (curr > 60 && instances * 2 <= INF) {
			instances *= 2;
			i += 11;
		} else if (curr < 25 && instances > 1) {
			instances = (instances + 1) / 2;
			i += 11;
		} else {
			i++;
		}
	}
	return instances;
}
int main() {
	int n; cin >> n;
	int len; cin >> len;
	vector<int> a(len);
	for (int i = 0; i < len; i++) {
		cin >> a[i];
	}
	cout << result(a, n);

	return 0;
}