class Trie
{
public:
    struct Node
    {
        bool isWord;
        map<char, Node *> edges;
        Node() : isWord(false) {}
    };
    /** Initialize your data structure here. */

    Node *root;
    Trie()
    {
        root = new Node();
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *curr = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (curr->edges.find(word[i]) == curr->edges.end())
            {
                curr->edges.insert({word[i], new Node()});
            }
            curr = curr->edges.find(word[i])->second;
        }
        curr->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++)
        {
            if (curr->edges.find(word[i]) == curr->edges.end())
            {
                return false;
            }
            curr = curr->edges.find(word[i])->second;
        }
        return curr->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *curr = root;
        int n = prefix.length();
        for (int i = 0; i < n; i++)
        {
            if (curr->edges.find(prefix[i]) == curr->edges.end())
            {
                return false;
            }
            curr = curr->edges.find(prefix[i])->second;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */