class Solution {
   public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_map<string, int> wordMap;
        int n = wordList.size();
        for (int i = 0; i < n; i++) {
            wordMap[wordList[i]] = 1;
        }
        if (wordMap.count(endWord) == 0) return 0;

        queue<pair<string, int> > q;
        unordered_map<string, int> done;
        q.push(make_pair(beginWord, 1));

        while (!q.empty()) {
            pair<string, int> front = q.front();
            q.pop();
            string val = front.first;
            if (done.count(val)) continue;
            done[val]++;

            int depth = front.second;
            if (val == endWord) return depth;
            for (int i = 0; i < val.length();
                 i++) {  // NOTE: It makes more sense to check every possible
                         // word that can be formed : 26 * len of word vs going
                         // through all the words for each word like we would do
                         // when building Classic Undirected Graph.
                for (int j = 0; j < 26; j++) {
                    string nw = val;
                    nw[i] = 'a' + j;
                    if (wordMap.count(nw)) {
                        if (nw != val) {
                            q.push(make_pair(nw, depth + 1));
                        }
                    }
                }
            }
        }
        return 0;
    }
};