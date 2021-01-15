// Keyboard Rows
// https://leetcode.com/problems/keyboard-row/

#include <bits/stdc++.h>
using namespace std;

public:
vector<string> findWords(vector<string>& words) {
    string dict[3] = {"qwertyuiop", "asdfghjkl.", "zxcvbnm..."};
    vector<map<char, int> > vc(3);
    vector<string> solution;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 10; j++) {
            if (dict[i][j] == '.') break;
            vc[i][dict[i][j]] = 1;
        }
    }

    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        string useWord = words[i];
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        int idx = 0;
        char firstChar = word[0];
        for (int j = 0; j < 3; j++) {
            map<char, int> mp = vc[j];
            if (mp.find(firstChar) != mp.end()) {
                idx = j;
                break;
            }
        }
        bool found = true;

        for (int k = 1; k < word.length(); k++) {
            map<char, int> nmp = vc[idx];

            if (nmp.find(word[k]) == nmp.end()) {
                found = false;
                break;
            }
        }

        if (found) solution.push_back(useWord);
    }
    return solution;
}