class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int mod = 1e9 + 7;
        
        // dp[r][c] stores the max score from (n-1, n-1) to (r, c)
        vector<vector<int>> dp(n, vector<int>(n, -1));
        // ways[r][c] stores the number of ways to get max score at (r, c)
        vector<vector<int>> ways(n, vector<int>(n, 0));
        
        // Base cases for the starting position
        dp[n - 1][n - 1] = 0;
        ways[n - 1][n - 1] = 1;
        
        // Convert 'S' and 'E' to '0' so we can cleanly add values
        board[0][0] = '0';
        board[n - 1][n - 1] = '0';
        
        // Process the board from bottom-right to top-left
        for (int r = n - 1; r >= 0; --r) {
            for (int c = n - 1; c >= 0; --c) {
                // Skip the start cell since it's already initialized, and skip obstacles
                if ((r == n - 1 && c == n - 1) || board[r][c] == 'X') {
                    continue;
                }
                
                int max_val = -1;
                
                // Define the 3 previous cells we could have come from (down, right, down-right)
                int prev_cells[3][2] = {{r + 1, c}, {r, c + 1}, {r + 1, c + 1}};
                
                // 1. Find the maximum score among the valid previous cells
                for (auto& p : prev_cells) {
                    int pr = p[0], pc = p[1];
                    if (pr < n && pc < n && dp[pr][pc] != -1) {
                        max_val = max(max_val, dp[pr][pc]);
                    }
                }
                
                // 2. If at least one valid path reached a previous cell
                if (max_val != -1) {
                    dp[r][c] = max_val + (board[r][c] - '0');
                    
                    // Accumulate the number of ways from all predecessors that match the max_val
                    for (auto& p : prev_cells) {
                        int pr = p[0], pc = p[1];
                        if (pr < n && pc < n && dp[pr][pc] == max_val) {
                            ways[r][c] = (ways[r][c] + ways[pr][pc]) % mod;
                        }
                    }
                }
            }
        }
        
        // If the top-left cell is unreachable, return {0, 0}
        if (dp[0][0] == -1) {
            return {0, 0};
        }
        
        return {dp[0][0], ways[0][0]};
    }
};