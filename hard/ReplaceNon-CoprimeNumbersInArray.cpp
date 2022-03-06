class Solution {
    using ll = long long;
public:
    ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
    vector<int> replaceNonCoprimes(vector<int>& nums) {

 
        vector<int> result;
        int i = 0;
        int n = nums.size();
        int prev = 1;

             while(i < n) {
            ll last = nums[i];
            i++;

            while(i < n && gcd(last, nums[i]) > 1) {
                ll g = gcd(last, nums[i]);
                ll prod = last * nums[i];
                last = prod/g;
                i++;
            }
            while(result.size() >= 1 && gcd(result[result.size() -1], last) > 1) {
                
                ll g = gcd(result[result.size() -1], last);
                ll prod = last * result[result.size() -1];
                result.pop_back();
                last = prod/g;
            }
            result.push_back(last);
        }

        
        return result;
     
        
        
    }
};