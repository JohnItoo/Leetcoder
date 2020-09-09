class Solution {
public:
    string reverseWords(string s) {
        if (s.length() == 0 ) return s;
        if (std::all_of(s.begin(), s.end(), [](char c) {
        return std::isspace(static_cast<unsigned char>(c));
        })) return "";
        istringstream st(s);
        vector<string> results((istream_iterator<string>(st)),
                               istream_iterator<string>());
        string res = "";

        for (int i = results.size() - 1; i > 0; i--) {
            res += results[i];
            res += " ";
        }
        res += results[0];

        return res;
    }
};