class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    static constexpr int LOG = 17;

    vector<vector<int>> adj;
    vector<vector<int>> up;
    vector<int> depth;
    vector<long long> pow2;

    void dfs(int u, int p) {
        up[0][u] = p;

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }
    }

    int lca(int a, int b) {
        if (depth[a] < depth[b]) swap(a, b);

        int diff = depth[a] - depth[b];

        for (int k = 0; k < LOG; k++) {
            if (diff & (1 << k))
                a = up[k][a];
        }

        if (a == b) return a;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][a] != up[k][b]) {
                a = up[k][a];
                b = up[k][b];
            }
        }

        return up[0][a];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;

        adj.assign(n + 1, {});
        depth.assign(n + 1, 0);
        up.assign(LOG, vector<int>(n + 1, 0));

        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0);

        for (int k = 1; k < LOG; k++) {
            for (int v = 1; v <= n; v++) {
                up[k][v] = up[k - 1][ up[k - 1][v] ];
            }
        }

        pow2.assign(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int u = q[0];
            int v = q[1];

            if (u == v) {
                ans.push_back(0);
                continue;
            }

            int w = lca(u, v);

            int dist = depth[u] + depth[v] - 2 * depth[w];

            ans.push_back(pow2[dist - 1]);
        }

        return ans;
    }
};