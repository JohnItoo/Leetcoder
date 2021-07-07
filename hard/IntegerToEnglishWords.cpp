class Solution {
public:
    string numberTo(string num, int idx, int end,  unordered_map<char, pair<string, string>> digMap,  unordered_map<string, string> oneTens) {
        if(idx >= num.size()) return "";
        if(idx == end) {
            if(num[idx] == '0') return "";
            else return digMap[num[idx]].first;
        }
        if(idx + 1 == end) {
            if(num[idx] == '0') return "" + numberTo(num, idx+1, end, digMap, oneTens);
            else if(num[idx] == '1') {
                string stub = num.substr(idx, 2);
                return oneTens[stub];
            } else {
                return digMap[num[idx]].second + numberTo(num, idx+1, end, digMap, oneTens);
            }
        }
        if(idx + 2 == end) {
            if(num[idx] == '0') return "" + numberTo(num, idx+1, end, digMap, oneTens);
            else {
                return digMap[num[idx]].first + "Hundred " + numberTo(num, idx+1, end, digMap, oneTens);
            }
        }
        string curr = "";
        int newEnd = idx;
        while((end - newEnd) % 3) newEnd++;
        
        
        
       string appendThis = "";
        bool allZeros = true;
        for(int start = idx; start <= newEnd; start++) {
            allZeros &= (num[start] == '0');
        }
        if(end - newEnd == 3) {
            appendThis = "Thousand ";
        } else if(end - newEnd == 6) {
            appendThis = "Million ";
        } else if(end - newEnd == 9) {
            appendThis = "Billion ";
        }
        if(allZeros) appendThis = "";
        return numberTo(num, idx, newEnd, digMap, oneTens) + appendThis + numberTo(num, newEnd+1, end, digMap, oneTens);
    }
    string numberToWords(int num) {
        
        unordered_map<string, string> oneTens = { {"10", "Ten "}, {"11", "Eleven "},
                                       {"12", "Twelve "}, {"13", "Thirteen "},
                                       {"14", "Fourteen "}, {"15", "Fifteen "},
                                       {"16", "Sixteen "}, {"17", "Seventeen "},
                                       {"18", "Eighteen "}, {"19", "Nineteen "}};

        unordered_map<char, pair<string, string> > digMap = { {'1' , {"One ", "Ten "}},
                                 {'2', {"Two ", "Twenty "}},
                                 {'3', {"Three ", "Thirty "}},
                                 {'4', {"Four ", "Forty "}},
                                 {'5', {"Five ", "Fifty "}},
                                 {'6', {"Six ", "Sixty "}},
                                 {'7', {"Seven ", "Seventy "}},
                                 {'8', {"Eight ", "Eighty "}},
                                 {'9', {"Nine ", "Ninety "}}
                                };
        string numberString = to_string(num);
        int n = numberString.size();
        if(numberString[0] == '0') return "Zero";
        string res = numberTo(numberString, 0, n-1, digMap, oneTens);
        res.pop_back();
        return res;
    
    }
};