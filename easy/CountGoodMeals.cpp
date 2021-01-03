#define ll long long int 
class Solution {
public:
    int countPairs(vector<int>& d) {
        map<ll, ll > mp;
        int n = d.size();
        for(int i = 0; i < n; i++) {
            mp[d[i]]++;
        }
        ll ans = 0;
        ll md = 1e9 + 7;
        map<pair<ll, ll>, ll> freq;
        for(auto ii : mp) {
            ll key = ii.first;
            for(ll i =0; i < 32; i++) {
                ll tot = 1 << i;
                ll rem = tot - key;
                ll curr = 0;
                if(rem <= 0) continue;
                if(mp.find(rem) == mp.end()) continue;
                if(key == rem && mp[key] > 1) {
                    ll add = (ll) (mp[key] *  (mp[key]-1));
                    add/= 2;
                    curr  += add;
                
                } else if (key != rem) {
                    curr +=  (ll) (mp[key] * mp[rem]) % md;
                }
                pair<ll, ll> ii = make_pair(min(key, rem), max(key, rem));

                
                if(freq.find(ii) == freq.end() && curr > 0) {
                    ans += curr;
                    ans %= md;
                    freq[ii] = 1;
                }
            }
        }
        return ans;
        
    }
};