class Solution {
    struct Trie {
        unordered_map<char, Trie*> edges; 
        bool isWordEnd = false;
        Trie() {}
    };
public:
    Trie* buildTrie(vector<string>& words) {
          Trie* root = new Trie();
        for(string& word : words) {
            Trie* curr = root;
            int len = word.size();
            for(int i = 0; i < len; i++) {
                Trie* newNode = new Trie();
               if ((curr->edges).find(word[i]) == (curr->edges).end()) {
                   (curr->edges).insert({word[i], newNode});
               }
                curr = (curr->edges)[word[i]];
            }
            curr->isWordEnd = true;
        }
        return root;
    }
    
    void backtrack(int i , int j, vector<vector<char>>& board,
                   set<string>& res, Trie* currentTrieNode, string currentStr) {
        
        int n = board.size();
        int m = board[0].size();
        if(i < 0 || i >= n || j < 0 || j >= m || board[i][j] == ' ' || (currentTrieNode->edges).find(board[i][j]) == (currentTrieNode->edges).end()) return;

       
        Trie* newTrieNode = (currentTrieNode->edges)[board[i][j]];
        int dir[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
       
        
        currentStr = currentStr+ board[i][j];
        if(newTrieNode->isWordEnd) {
            res.insert(currentStr);
        }
        char c = board[i][j];
        board[i][j] = ' ';

        for(int idx = 0; idx < 4; idx++) {
            backtrack(i+ dir[idx][0], j + dir[idx][1], board, res, newTrieNode, currentStr);
        }
        board[i][j] = c;
     
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        
        Trie* root = buildTrie(words);
        int n = board.size();
        int m = board[0].size();
        
        set<string> aux;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                string here;
                backtrack(i, j, board, aux, root, here);
            }
        }
        for(auto& ax : aux) {
            res.push_back(ax);
        }

        return res;
        
    }
};