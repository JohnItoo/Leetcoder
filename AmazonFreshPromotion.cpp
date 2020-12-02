#include <bits/stdc++.h>
using namespace std;

bool matches(string shopping, string required) {
	return required == "anything" || shopping == required;
}

int isWinner(vector<string> shoppingCart, vector<vector<string> > codeList) {
	int n = shoppingCart.size();
	int groups = codeList.size();

	int doneGroups = 0;
	int currentGroup = 0;
	int i = 0; //first item of shoppingCart.
	while (i < n && currentGroup < groups) {
		int j =  0; //first item of currentGroup.
		bool isDone = false;

		while (i < n && j < codeList[currentGroup].size()) {
			if (matches(shoppingCart[i], codeList[currentGroup][j])) {
				i++;
				j++;
			} else {
				i++;
				break;
			}
		}
		if (j == codeList[currentGroup].size()) {
			doneGroups += 1;
			currentGroup++;
		}
	}

	if (doneGroups == groups) return 1;
	else return 0;
}

int main() {
	int n; cin >> n;
	vector<string> shoppingCart(n);
	for (int i = 0; i < n; i++) cin >> shoppingCart[i];
	int m; cin >> m;
	vector<vector<string> >  codeList(m);
	for (int i = 0; i < m; i++) {
		int len; cin >> len;
		vector<string> curr(len);
		for (int j = 0; j < len; j++) cin >> curr[j];
		codeList[i] = curr;
	}

	cout << isWinner(shoppingCart, codeList) << endl;
	return 0;
}