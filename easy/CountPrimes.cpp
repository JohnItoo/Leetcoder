class Solution {

    //O(NlogN) Sieve.
   public:
    int countPrimes(int n) {
        vector<int> arr(n + 5, 0);
        if (n < 2) return 0;
        arr[1] = 0;
        for (int i = 2; i < n; i++) {
            if (arr[i] != 0) continue;
            for (int j = 2 * i; j < n; j += i) {
                arr[j] = i;
            }
        }
        int primes = 0;
        for (int i = 2; i < n; i++) {
            if (arr[i] == 0) primes++;
        }
        return primes;
    }
};