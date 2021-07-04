class Solution {
public:
 int md = 1e9 + 7;
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
    int countGoodNumbers(long long n) {
        long long ans = 1;
        long long primes = n/2;
        long long evs = n - primes;
        
        return (binpow(5, evs,md) * binpow(4, primes,md))%md; 
        
        return ans;
    }
};