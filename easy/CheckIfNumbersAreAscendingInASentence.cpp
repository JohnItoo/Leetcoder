class Solution {
 public:
  bool areNumbersAscending(string s) {
    int n = s.size();
    vector<int> a;
    int last = -1;
    for (int i = 0; i < n;) {
      if (s[i] >= '0' && s[i] <= '9') {
        string cal;
        while (s[i] >= '0' && s[i] <= '9') {
          cal.push_back(s[i]);
          i++;
        }
        int nxt = stoi(cal);
        if (nxt <= last) {
          return false;
        }
        last = nxt;
        a.push_back(nxt);

      } else {
        i++;
      }
    }
    return true;
  }
};