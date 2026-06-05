class Solution {
public:
    struct Node {
        long long cnt;
        long long wav;
    };

    string s;
    Node dp[20][2][11][11][2];
    bool vis[20][2][11][11][2];

    Node dfs(int pos, int tight, int prev1, int prev2, int started) {
        if (pos == s.size()) {
            return {1, 0};
        }

        if (vis[pos][tight][prev1][prev2][started])
            return dp[pos][tight][prev1][prev2][started];

        vis[pos][tight][prev1][prev2][started] = true;

        Node ans = {0, 0};

        int lim = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= lim; d++) {
            int ntight = tight && (d == lim);

            if (!started && d == 0) {
                Node cur = dfs(pos + 1, ntight, 10, 10, 0);
                ans.cnt += cur.cnt;
                ans.wav += cur.wav;
            }
            else if (!started) {
                Node cur = dfs(pos + 1, ntight, d, 10, 1);
                ans.cnt += cur.cnt;
                ans.wav += cur.wav;
            }
            else {
                Node cur = dfs(pos + 1, ntight, d, prev1, 1);

                long long add = 0;

                if (prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        add = 1;
                }

                ans.cnt += cur.cnt;
                ans.wav += cur.wav + add * cur.cnt;
            }
        }

        return dp[pos][tight][prev1][prev2][started] = ans;
    }

    long long solve(long long x) {
        if (x <= 0) return 0;

        s = to_string(x);
        memset(vis, 0, sizeof(vis));

        Node res = dfs(0, 1, 10, 10, 0);
        return res.wav;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};