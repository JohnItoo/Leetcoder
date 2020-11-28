class Solution {
public:
  int maxRepeating(string sequence, string word) {
    int sl = sequence.length();
    int wl = word.length();
    int ans = 0;

    for (int i = 0; i < sl; i++) {
      if (sequence[i] != word[0]) continue;
      int j = i;
      int ct = 0;
      int len = 0;

      while (j < sl && sequence[j] == word[(j - i) % wl] ) {
        len++;
        if (len == wl) {
          ct++;
          len = 0;
        }
        j++;
      }
      ans = max(ans, ct);
    }
    return ans;
  }
};