class Solution {
public:
    int maximumXorProduct(long long a, long long b, int n) {
        const long long MOD = 1000000007LL;

        long long mask = (1LL << n) - 1;

        long long A = a & (~mask);
        long long B = b & (~mask);

        a &= mask;
        b &= mask;

        for (int i = n - 1; i >= 0; i--) {
            long long bit = 1LL << i;

            bool abit = a & bit;
            bool bbit = b & bit;

            if (abit == bbit) {
                if (!abit) {
                    A |= bit;
                    B |= bit;
                } else {
                    A |= bit;
                    B |= bit;
                }
            } else {
                if (A < B) {
                    A |= bit;
                } else {
                    B |= bit;
                }
            }
        }

        return (A % MOD) * (B % MOD) % MOD;
    }
};