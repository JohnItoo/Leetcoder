//https://leetcode.com/problems/group-anagrams/
//Question 49

class Anag {
private: string value;
  int index;

public: Anag() {}

public:
  void set_value(string value) {
    this->value = value;
  }
  void set_index(int index) {
    this->index = index;
  }
  int get_index() {
    return index;
  }

  string get_value() {
    return value;
  }

};

class Solution {

private: static bool comp(Anag a, Anag b) {
    if (a.get_value() == b.get_value()) {
      return a.get_index() < b.get_index();
    }
    return a.get_value() < b.get_value();
  }
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<Anag> anags;
    int n = strs.size();
    for (int i = 0; i < n; i++) {
      Anag anag = Anag();
      string s = strs[i];
      sort(s.begin(), s.end());
      anag.set_value(s);
      anag.set_index(i);
      anags.push_back(anag);
    }
    sort(anags.begin(), anags.end(), comp);
    vector<vector<string>> result;
    int i = 0;
    while (i < n) {
      string perm = anags[i].get_value();
      vector<string> current;
      current.push_back(strs[anags[i].get_index()]);
      int j = i + 1;
      while (j < n && perm == anags[j].get_value()) {
        current.push_back(strs[anags[j].get_index()]);
        j++;
      }
      i = j;
      result.push_back(current);
    }
    return result;
  }
};