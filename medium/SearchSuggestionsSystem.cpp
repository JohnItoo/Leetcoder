struct TrieNode {
    bool isWord;
    map<char, TrieNode*> edges;
    TrieNode(): isWord(false) {}
    TrieNode(bool word): isWord(word) {}
};

class Solution {
public:
    set<string> visit(TrieNode* trie, map<string, set<string>>& words, string pref) {
        set<string> h;
        if(trie->isWord) {
            h.insert("");
            return h;
        }
        
        for(auto ii : trie->edges) {
            char c = ii.first;
            TrieNode* child = ii.second;
            string one = "";
            one.push_back(c);
            string prefix = pref;
            prefix.push_back(c);
            set<string> res = visit(child, words, prefix);
            for(string suffix: res) {
                h.insert(one + suffix);
            }
        }
        words.insert({pref, h});
        return h;
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode* root =  new TrieNode();
        
        for(string product: products) {
            TrieNode* curr = root;
            int n = product.size();
            for(int i = 0; i < n; i++) {
                char c = product[i];
                if(curr->edges.find(c) == curr->edges.end()) {
                    curr->edges.insert({c, new TrieNode()});
                }
                curr = curr->edges.find(c)->second;
            }
            char em = '1';
            curr->edges.insert({em, new TrieNode(true)});
        }
        map<string, set<string>> words;
        visit(root, words, "");
         vector<vector<string>> ans;
        
        TrieNode* curr = root;
       
        bool stop = false;
        for(int i = 0; i < searchWord.size(); i++) {
            if(stop) {
                ans.push_back(vector<string>(0));
            } else {
                vector<string> currV;
                char c = searchWord[i];
                if(curr->edges.find(c) == curr->edges.end()) {
                    stop = true;
                    ans.push_back(vector<string>(0));
                } else {
                    set<string> hset = words[searchWord.substr(0, i+1)];
                    string p = searchWord.substr(0, i+1);
                    int ct = 0;
                    for(string hs: hset) {
                        if(ct == 3) break;
                        ct++;
                        hs.pop_back();
                        currV.push_back(p + hs);
                    }
                    curr = curr->edges[c];
                    ans.push_back(currV);
                }
            }
        }
        return ans;
        
    }
};