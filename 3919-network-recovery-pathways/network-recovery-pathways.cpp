#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, long long>>> adj(n);
        vector<int> indeg(n, 0);
        long long maxCost = 0;

        // Build the graph and track the maximum edge cost
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            long long cost = edge[2];
            adj[u].push_back({v, cost});
            indeg[v]++;
            if (cost > maxCost) {
                maxCost = cost;
            }
        }

        // Kahn's Algorithm for Topological Sorting
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (const auto& edge : adj[u]) {
                if (--indeg[edge.first] == 0) {
                    q.push(edge.first);
                }
            }
        }

        long long left = 0, right = maxCost;
        int ans = -1;

        // DP check function to see if a given min_w is possible
        auto check = [&](long long min_w) {
            vector<long long> dp(n, 1e18); // 1e18 acts as infinity
            dp[0] = 0;

            for (int u : topo) {
                // If unreachable or exceeds k, stop exploring from u
                if (dp[u] > k) continue; 
                // Cannot pass through offline intermediate nodes
                if (!online[u]) continue;

                for (const auto& edge : adj[u]) {
                    int v = edge.first;
                    long long cost = edge.second;
                    
                    // Only consider edges meeting the binary search threshold
                    if (cost >= min_w) {
                        if (dp[u] + cost < dp[v]) {
                            dp[v] = dp[u] + cost;
                        }
                    }
                }
            }
            return dp[n - 1] <= k;
        };

        // Binary search on the maximum path score
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(mid)) {
                ans = mid;         // Possible, try for a higher score
                left = mid + 1;
            } else {
                right = mid - 1;   
            }
        }

        return ans;
    }
};