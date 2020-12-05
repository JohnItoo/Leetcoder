#include <bits/stdc++.h>
using namespace std;

vector<string> solve(int k, vector<string> keywords, vector<string> reviews) {
	int n = keywords.size();
	map<string, int> mp;
	for (int i = 0; i < n; i++) mp[keywords[i]]++;

	for (string review : reviews) {
		transform(review.begin(), review.end(), review.begin(), ::tolower);
		int last = 0;
		int i = 0;
		set<string> keys;
		while (i < review.length()) {
			if (review[i] == ' ') {
				string sub = review.substr(last, i - last);
				last = i + 1;
				i = i + 1;
				if (mp.find(sub) != mp.end()) keys.insert(sub);
			} else {
				i++;
			}
		}
		string suff = review.substr(last, review.length() - last);
		if (mp.find(suff) != mp.end()) keys.insert(suff);

		for (string key : keys) {
			mp[key]++;
		}
	}
}

int main() {
	int k; cin >> k;
	int n; cin >> n;
	vector<string> keywords(n);
	for (int i = 0; i < n; i++)  cin >> keywords[i];
	int r; cin >> r;
	vector<string> reviews(r);
	for (int i = 0; i < r; i++) cin >> reviews[i];

	vector<string> result = solve(k, keywords, reviews);
	for (string ans : result) cout << ans << endl;



	return 0;
}