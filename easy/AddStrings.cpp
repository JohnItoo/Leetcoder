class Solution {
public:
    string addStrings(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        int i = n-1;
        int j = m-1;
        int carry = 0;
        string ans;
        while(i >= 0 || j >= 0) {
           int val1 = 0;
            if( i >= 0) {
                string valone = num1.substr(i, 1);
                val1 = stoi(valone);
            }
            int val2 = 0;
            if(j >= 0) {
                string valtwo = num2.substr(j, 1);
                val2 = stoi(valtwo);
            }
            int add = carry + val1 + val2;
            int append = add %10;
            carry = add / 10;
            string suff = to_string(append);
            ans.append(suff);
            i--;
            j--;
        }
        if(carry > 0) {
            string suff = to_string(carry);
            ans.append(suff);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};