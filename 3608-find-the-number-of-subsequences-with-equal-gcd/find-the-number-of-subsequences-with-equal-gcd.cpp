class Solution {
public:
    const int MOD = 1e9 + 7;
    int n;
    vector<int> nums;
    vector<vector<vector<int>>> dp;

    int solve(int i, int g1, int g2) {
        if (i == n)
            return (g1 > 0 && g1 == g2);

        if (dp[i][g1][g2] != -1)
            return dp[i][g1][g2];

        long long ans = 0;

        // Skip
        ans += solve(i + 1, g1, g2);

        // Put in first subsequence
        ans += solve(i + 1, gcd(g1, nums[i]), g2);

        // Put in second subsequence
        ans += solve(i + 1, g1, gcd(g2, nums[i]));

        return dp[i][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();

        int mx = *max_element(nums.begin(), nums.end());

        dp.assign(n,
                  vector<vector<int>>(mx + 1,
                  vector<int>(mx + 1, -1)));

        return solve(0, 0, 0);
    }
};