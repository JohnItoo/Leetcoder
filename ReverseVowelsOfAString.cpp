class Solution {
public:
    string reverseVowels(string a) {
        char arr[10] = {'A', 'a', 'e' ,'E', 'i', 'I', 'o', 'O', 'u', 'U'};
        map<char, int> mp;
        for(char vowel : arr) {
            mp[vowel]++;
        }
        int n = a.length();
        int i = 0; int j = n-1;
        
        while(i < j) {
            if(mp.find(a[i]) == mp.end()) {
                i++;
            }
            if(mp.find(a[j]) == mp.end()) {
                j--;
            }
            
            if(mp.find(a[j]) != mp.end() && mp.find(a[i]) != mp.end()) {
                swap(a[i], a[j]);
                i++; j--;
            } 
        }
        
        return a;
        
        
    }
};