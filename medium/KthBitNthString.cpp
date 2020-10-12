//Question 1545;
class Solution {

    private: string invert(string s) {
        string q = "";
      for(int i = 0; i < s.length(); i++) {
          if(s[i] == '1') q.push_back('0');
          else q.push_back('1');
      }
        return q;
    }
    private: int K = 0;
    string arr[21];
    
public:
    char findKthBit(int n, int k) {
        K = k;
        arr[0] = "0";
        for(int i = 1; i <= n; i++) {
            string s = arr[i-1] + "1";
            string inv = invert(arr[i-1]);
             std::reverse(inv.begin(), inv.end()); 
            string q =  s + inv;
            arr[i] = q;
        }
        return arr[n][k-1];
        
    }
};