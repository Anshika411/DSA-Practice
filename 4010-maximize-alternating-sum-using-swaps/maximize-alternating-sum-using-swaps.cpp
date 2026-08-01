class Solution {
public:
    vector<int> parent, rankv;

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // Path Compression
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        // Union by Rank
        if (rankv[px] < rankv[py])
            parent[px] = py;
        else if (rankv[px] > rankv[py])
            parent[py] = px;
        else {
            parent[py] = px;
            rankv[px]++;
        }
    }

    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        int n = nums.size();

        parent.resize(n);
        rankv.assign(n, 0);

        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Step 1: Build connected components
        for (auto &e : swaps)
            unite(e[0], e[1]);

        // Step 2: Group indices by root
        unordered_map<int, vector<int>> comp;

        for (int i = 0; i < n; i++) {
            comp[find(i)].push_back(i);
        }

        long long ans = 0;

        // Step 3: Process every connected component
        for (auto &it : comp) {
            vector<int> indices = it.second;
            vector<int> values;

            int evenCnt = 0;

            // Collect values and count even indices
            for (int idx : indices) {
                values.push_back(nums[idx]);
                if (idx % 2 == 0)
                    evenCnt++;
            }

            sort(values.begin(), values.end());

            int m = values.size();

            // Largest evenCnt values go to even indices
            for (int i = m - 1; i >= m - evenCnt; i--)
                ans += values[i];

            // Remaining values go to odd indices
            for (int i = 0; i < m - evenCnt; i++)
                ans -= values[i];
        }

        return ans;
    }
};