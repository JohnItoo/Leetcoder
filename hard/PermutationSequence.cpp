class Solution {
public:
    string getPermutation(int n, int k) {
        string sequence;
        for (int i = 1; i <= n; i++) {
            char c = i + '0';
            sequence.push_back(c);
        }
        int i = 1;
        do {
            if (i == k) break;
            i += 1;
        } while (next_permutation(sequence.begin(), sequence.end()) && i < k);
        return sequence;
    }
};