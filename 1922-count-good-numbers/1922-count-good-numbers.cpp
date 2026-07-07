class Solution {
public:

  static const long long MOD = 1e9 + 7;

    long long power(long long x, long long p) {
        if(p == 0) return 1;

        long long y = power(x, p / 2);

        y = (y * y) % MOD;

        if(p%2 != 0)
            y = (y * x) % MOD;

        return y;
    }

    int countGoodNumbers(long long n) {

        long long no_odd = n / 2;
        long long no_even = n - no_odd;

        return (power(5, no_even) * power(4, no_odd)) % MOD;
    }
};