class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> present(MAXX, false);
        for (int x : nums)
            present[x] = true;

        vector<bool> dp(MAXX, false);
        dp[0] = true;

        for (int step = 0; step < 3; step++) {
            vector<bool> next(MAXX, false);
            for (int xr = 0; xr < MAXX; xr++) {
                if (!dp[xr]) continue;
                for (int v = 0; v < MAXX; v++) {
                    if (present[v])
                        next[xr ^ v] = true;
                }
            }
            dp = next;
        }

        int ans = 0;
        for (bool x : dp)
            if (x) ans++;

        return ans;
    }
};