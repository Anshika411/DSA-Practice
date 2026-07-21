class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        if (accounts.empty())
            return 0;

        int n = accounts.size(); //no. of person
        int m = accounts[0].size();
        int maxWealth = 0;

        for (int i = 0; i < n; i++) {
            int currWealth = 0;
            for (int j = 0; j < m; j++) {
                currWealth += accounts[i][j];
            }
            maxWealth = max(maxWealth, currWealth);
        }

        return maxWealth;
    }
};