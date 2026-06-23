class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        long long mod = 1e9 + 7;
        
        if (n == 1) return m;
        if (n == 2) return (1LL * m * (m - 1)) % mod;

        vector<long long> dp0(m + 1, 0);
        vector<long long> dp1(m + 1, 0);

        for (int y = 1; y <= m; ++y) {
            dp0[y] = y - 1;
            dp1[y] = m - y;
        }

        for (int i = 2; i < n; ++i) {
            vector<long long> next_dp0(m + 1, 0);
            vector<long long> next_dp1(m + 1, 0);

            long long sum1 = 0;
            for (int y = 1; y <= m; ++y) {
                next_dp0[y] = sum1;
                sum1 = (sum1 + dp1[y]) % mod;
            }

            long long sum0 = 0;
            for (int y = m; y >= 1; --y) {
                next_dp1[y] = sum0;
                sum0 = (sum0 + dp0[y]) % mod;
            }

            dp0 = move(next_dp0);
            dp1 = move(next_dp1);
        }

        long long ans = 0;
        for (int y = 1; y <= m; ++y) {
            ans = (ans + dp0[y] + dp1[y]) % mod;
        }

        return ans;
    }
};