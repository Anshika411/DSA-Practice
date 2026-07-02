class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int, int>> dq;
        
        dist[0][0] = grid[0][0];
        if (grid[0][0] == 1) {
            dq.push_back({0, 0});
        } else {
            dq.push_front({0, 0});
        }
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();
       
            if (r == m - 1 && c == n - 1) {
                return health - dist[r][c] >= 1;
            }
           
            for (int i = 0; i < 4; ++i) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    int next_cost = dist[r][c] + grid[nr][nc];
                 
                    if (next_cost < dist[nr][nc]) {
                        dist[nr][nc] = next_cost;
                        
                    
                        if (grid[nr][nc] == 1) {
                            dq.push_back({nr, nc});
                        } else {
                            dq.push_front({nr, nc});
                        }
                    }
                }
            }
        }
        
        return false;
    }
};