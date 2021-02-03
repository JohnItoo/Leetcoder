#include <bits/stdc++.h>
using namespace std;

struct myComp {

	bool operator()(  pair<int, string> const& a,
	                  pair<int, string> const& b) const noexcept {
		if (a.first == b.first) return a.second > b.second;
		return a.first < b.first;
	}

};

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
			if (!(review[i] >= 'a' && review[i] <= 'z')) {
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
	priority_queue<pair<int, string>, vector<pair<int, string> >, myComp> pq;

	for (auto keyword : mp) {
		if (keyword.second == 1) continue;
		pair<int, string> ii = make_pair(keyword.second - 1, keyword.first);
		pq.push(ii);
	}
	int i = 0;
	vector<string> sol;
	while (i < k) {
		pair<int, string> tp = pq.top(); pq.pop();
		sol.push_back(tp.second);
		i++;
	}
	return sol;
}

int main() {
	int k; cin >> k;
	int n; cin >> n;
	vector<string> keywords(n);
	for (int i = 0; i < n; i++)  cin >> keywords[i];
	int r; cin >> r;
	cin >> ws; //remove whitespace
	vector<string> reviews(r);
	for (int i = 0; i < r; i++) {
		string s; getline(cin, s); // get strings as lines
		reviews[i] = s;
	}

	vector<string> result = solve(k, keywords, reviews);
	for (string ans : result) cout << ans << endl;



	return 0;
}