class Solution {
public:
    int solve(vector<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0)
            return 0;
        if (amount < 0)
            return INT_MAX;

        if (dp[amount] != -1)
            return dp[amount];

        int ans = INT_MAX;

        for (int coin : coins) {
            int res = solve(coins, amount - coin, dp);

            if (res != INT_MAX)
                ans = min(ans, res + 1);
        }

        dp[amount] = ans;
        return dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);

        int ans = solve(coins, amount, dp);

        if (ans == INT_MAX)
            return -1;

        return ans;
    }
};